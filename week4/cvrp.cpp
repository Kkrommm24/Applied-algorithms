#include <bits/stdc++.h>
using namespace std;
#define N 100

int n, K, Q;
int d[N];
int c[N][N]; // matrix kcach
// Var
int Y[N];
int X[N];
int load[N];
int nbSegments;
int nbRouteUsed;
int f; // độ dài quãng đường
int f_min;
bool visited[N];

void input(){
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    
}

void printSolution(){
    for(int k = 1; k <= K; k++) cout << Y[k] << " " << endl;
    for(int i = 1; i <= n; i++) cout << X[i] << " " << endl;
    for(int k = 1; k <= K; k++){
        cout << "route[" << k << "]: 0";
        for(int i = Y[k]; i != 0; i = X[i])
            cout << i << " ";
            cout << "0, load =  " << load[k] << endl;
    }
    cout << "nbRouteUsed = " << nbRouteUsed << " nbSegments = " << nbSegments << endl;
}

void solution(){
    if (f < f_min){
        f_min = f;
        // printSolution();
        // cout << "Update best " << f_min << endl;
    }
}

bool checkX(int v, int i, int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void TryX(int i, int k){
    if(i == 0){
        if(k < K)
            TryX(Y[k+1], k+1);
        return;
    }
    for (int v = 0; v <= n; v++) {
        if (checkX(v, i, k)) {
            X[i] = v; visited[v] = true;
            f = f + c[i][v]; load[k] += d[v];
            nbSegments += 1;
            if (v == 0){
                if (k < K){
                    TryX(Y[k+1], k+1);
                } else {
                    if (nbSegments == nbRouteUsed + n) solution();
                }
            }else{
                TryX(v, k);
            }
            visited[v] = false;  
            f = f - c[i][v]; load[k] -= d[v];
            nbSegments -= 1;
        }
    }
}
bool checkY(int v, int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}


void TryY(int k) {
    // for (int v = Y[k-1] + 1; v <= n-K+k; v++) {
    for (int v = (Y[k-1] == 0 ? 0 : Y[k-1] + 1); v <= n; v++) {
        if (checkY(v, k)) {
            Y[k] = v; visited[v] = true;
            f = f + c[0][v]; load[k] += d[v];
            if(v > 0) nbSegments += 1;
            if (k == K){
                nbRouteUsed = nbSegments;
                TryX(Y[1], 1);
            }else {
                TryY(k + 1);
            }
            visited[v] = false;  
            f = f - c[0][v]; load[k] -= d[v];
            if(v > 0) nbSegments -= 1;
        }
    }
}

int main() {
    input();
    for (int v = 1; v <= n; v++) visited[v] = false;
    for (int k = 1; k <= K; k++) load[K] = 0;
    f = 0; f_min = 1e9; nbSegments = 0;
    Y[0] = 0;
    TryY(1);
    cout << f_min;
    return 0;
}