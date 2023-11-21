#include <bits/stdc++.h> 
using namespace std;
#define N 100
vector<int> T[N];
int m, n;
int x[N];
int load[N];
int res;
int c[N][N];
bool cfl[N][N];

void input(){
    cin >> m >> n;
    for(int t = 1; t <= m; t++){
        int k; 
        cin >> k;
        for(int j = 1; j <= k; j++){
            int c; 
            cin >> c; 
            T[c].push_back(t);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cfl[i][j] = false;
        }
    }

    int K;
    cin >> K;
    for(int k = 1; k <= K; k++){
        int i, j; 
        cin >> i >> j;
        cfl[i][j] = true; 
        cfl[j][i] = true;
    }
}

bool check(int t, int k){
    for(int i = 1; i < k; i++){
        if(cfl[i][k] && x[i] == t) 
            return false;
    }
    return true;
}

void solution(){
    int maxLoad = 0;
    for(int t = 1; t <= m; t++){
        maxLoad = max(maxLoad, load[t]);
    }
    if(maxLoad < res) 
        res = maxLoad;
}

void Try(int k){
    for(int v = 0; v < T[k].size(); v++){
        int t = T[k][v];
        if(check(t, k)){
            x[k] = t;
            load[t] += 1;
            if(k == n) 
                solution();
            else{
                if(load[t] < res)
                    Try(k+1);
            }
            load[t] -= 1;
        }
    }
}

int main(){
    input();
    for(int t = 1; t <= m; t++) 
        load[t] = 0; 
    res = INT_MAX;
    Try(1);
    cout << res;
    return 0;
}
