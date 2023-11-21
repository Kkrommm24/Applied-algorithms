#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define INF -1e9

long n, M;
long a[N], S[N];
long res[N];
void input(){
    cin >> n >> M;
    for(long i = 0; i < n; i++){
        cin >> a[i];
    }
}

void solution(){
    for(long i = 0; i < n; i++)
    cout << "So nghiem nguyen ko am: " << res[i];
}

void Truyhoi(long x, long y){
    for(long i = n; i > 0 ; i--){
        S[i] = S[i-1] - a[i]*i;
    }
}
int main(){
    input();
    

    return 0;
}