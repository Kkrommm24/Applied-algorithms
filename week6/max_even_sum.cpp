#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define INF -1e9

long n;
long a[N];
long SC[N], SL[N];
bool BC[N], BL[N];
void input(){
    cin >> n;
    for(long i = 0; i < n; i++){
        cin >> a[i];
    }
}

int main(){
    input();
    if(a[0] % 2 == 0){
        SC[0] = a[0]; BC[0] = true; BL[0] = false;
    }else{
        SL[0] = a[0]; BL[0] = true; BC[0] = false;
    }
    for(long i = 1; i < n; i++){
        if(a[i] % 2 == 0){
            if(BC[i-1] == true && SC[i-1] > 0){
                SC[i] = SC[i-1] + a[i];
            }else{
                SC[i] = a[i];
            }
            BC[i] = true;

            if(BL[i-1] == true){
                SL[i] = SL[i-1] + a[i]; BL[i] = true;
            }else BL[i] = false;
        }else{
            if(BL[i-1] == true){
                SC[i] = SL[i-1] + a[i]; BC[i] = true;
            }else BC[i] = false;

            if(BC[i-1] == true && SC[i-1] > 0){
                SL[i] = SC[i-1] + a[i];
            }else SL[i] = a[i];
            BL[i] = true;
        }
    }
    long res = INF;
    for(long i = 0; i < n; i++){
        if(BC[i] == true && SC[i] > res){
            res = SC[i];
        }
    }
    if(res == INF) cout << "NOT FOUND";
    else cout << res;
    return 0;
}