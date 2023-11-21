#include <bits/stdc++.h>
using namespace std;
#define N 10001
int a[N];
int n;
int S[N];
int trace[N];
int last;

int computeS(int i){
    if(i == 1){
        S[1] = 1;
    }else{
        if(S[i] == 0){
            S[i] = 1;
            for(int j = 1; j <= i-1; j++) if(a[j] < a[i]){
                int tmp = computeS(j);
                if(S[i] < tmp + 1) S[i] = tmp + 1;
            }
        }
    }
    return S[i];
}
void DPTopDown(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        int tmp = computeS(i);
        if(res < tmp) res = tmp;
    }
    cout << res;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    DPTopDown();
    // S[1] = 1; int res = S[1]; trace[1] = 0;
    // for(int i = 2; i <= n; i++){
    //     S[i] = 1; trace[i] = 0;
    //     for(int j = 1; j <= i-1; j++) if(a[j] < a[i]){
    //         if(S[i] < S[j] + 1){
    //             S[i] = S[j] + 1;
    //             trace[i] = j;
    //         }
    //     }
    //     if(res < S[i]){
    //         res = S[i]; last = i;
    //     }
    // }
    // int i = last;
    // stack<int> solution;

    // while(i > 0){
    //     // cout << a[i] << " ";
    //     solution.push(a[i]);
    //     i = trace[i];
    // }
    // while(!solution.empty()){
    //     int e = solution.top(); solution.pop();
    //     cout << e << " ";
    // }
    // cout << endl;
    // cout << res; 
    return 0;
}


