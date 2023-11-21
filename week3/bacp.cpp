//Liệt kê tất cả các bộ x1, x2,..., xn sao cho x1+..+xn = M (x1,..., xn luôn dương)
// tìm các bộ
#include <bits/stdc++.h> 
using namespace std;
#define N 100

int x[N];
int n, M;
int T = 0; // global var
bool check(int v, int k){
    if(k < n) return true;
    else return T + v;
}

void solution(){
    for(int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}
void Try(int k){
    for(int v = 1; v <= M - T - (n-k); v++){
        if(check(v, k)){
            x[k] = v;
            T = T + x[k];
            if(k == n) solution();
            else Try(k+1);
            T = T - x[k];
        }
    }
}

int main() { 
    cin >> n >> M;
    T = 0;
    Try(1);
    return 0;
}