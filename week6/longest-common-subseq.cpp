#include <bits/stdc++.h> 
using namespace std;

#define N 10001
/*
solve the longest common subsequence using dynamic programming
use trace for establishing the solution
*/
int X[N], Y[N];
int S[N][N]; // length of the longest subsequence of X[1], ..., X[i]; Y[1],...,Y[j]
int n, m;
char trace[N][N];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> X[i];
    }
    for(int j = 1; j <= m; j++){
        cin >> Y[j];
    }
}


int main(){
    input();
    for(int i = 0; i <= n; i++) S[i][0] = 0;
    for(int j = 0; j <= m; j++) S[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(X[i] == Y[j]){
                S[i][j] = S[i-1][j-1] + 1;
                trace[i][j] = 'D';
            }else{
                if(S[i-1][j] > S[i][j-1]){
                    S[i][j] = S[i-1][j]; trace[i][j] = 'U';
                }else{
                    S[i][j] = S[i][j-1]; trace[i][j] = 'L';
                }
            }
        }
    }
    // cout << "solution: ";
    // stack<int> S;
    int cnt = 0;
    int i = n; int j = m;
    while(i > 0 && j > 0){
        if(trace[i][j] == 'D'){
            // cout << X[i] << " ";
            // S.push(X[i]);
            cnt++;
            i = i - 1;
            j = j - 1;
        }else if(trace[i][j] == 'U'){
            i = i - 1;
        }else if(trace[i][j] == 'L'){
            j = j - 1;
        }
    }
    cout << cnt;
    // while(!S.empty()){
    //     int e = S.top();
    //     S.pop();
    //     cout << e << " ";
    // }
    // cout << endl;
    return 0;
}