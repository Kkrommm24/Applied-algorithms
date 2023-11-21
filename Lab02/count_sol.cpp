#include <bits/stdc++.h> 
using namespace std;
#define N 100

int x[N];
int a[N];
int t[N];
int n, M;
int T = 0; // global var
int cnt = 0;
int sum = 0;
bool check(int v, int k){
    if(k < n) return true;
    else return T + v * a[k] == M;
}

void Try(int k){
    for(int v = 1; v <= (M - T - (t[n] - t[k])) / a[k]; v++){ //- (t[n] - t[k])
        if(check(v, k)){
            x[k] = v;
            T = T + a[k] * x[k];
            if(k == n) cnt++;
            else Try(k+1);
            T = T - a[k] * x[k];
        }
    }
}

int main() { 
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        t[i] = sum;
    }
    T = 0;
    Try(1);
    cout << cnt << endl; // print the result
    return 0;
}
