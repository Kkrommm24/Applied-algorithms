//Liệt kê tất cả các bộ x1, x2,..., x7 sao cho 1000*H - 100*K + 100*I + 100*U + 10*C + 10*S + 2T - 62 = Q (1-9, các chữ khác nhau)
// tìm các bộ
#include <bits/stdc++.h> 
using namespace std;
#define N 8

long x[N];
long Q = 0;
long T = 0; // global var
long n;
bool used[N];

bool check(long v, long k){
    if(k == 7 && !used[v]){
        return T + 2*v == n;
    }else if(used[v]){
        return false;
    }
    return true;
}

void solution(){
    for(long i = 1; i <= 7; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}
void Try(long k){
    for(long v = 1; v <= 9; v++){
        if(check(v, k)){
            if(k == 1){
                x[k] = 1000*v;
                T = T + x[k];
                used[v] = true;
                Try(k+1);
                T = T - x[k];
                used[v] = false;
            }else if(k == 2){
                x[k] = 100*v;
                T = T - x[k];
                used[v] = true;
                Try(k+1);
                T = T + x[k];
                used[v] = false;
            }else if(k == 5 || k == 6){
                x[k] = 10*v;
                T = T + x[k];
                used[v] = true;
                Try(k+1);
                T = T - x[k];
                used[v] = false;
            }else if(k == 7){
                x[k] = 2*v;
                // solution();
                Q++;
            }else{
                x[k] = 100*v;
                T = T + x[k];
                used[v] = true;
                Try(k+1);
                T = T - x[k];
                used[v] = false;
            }
            
        }
    }
}

int main() { 
    cin >> n;
    n += 62;
    T = 0;
    Try(1);
    cout << Q;
    return 0;
}