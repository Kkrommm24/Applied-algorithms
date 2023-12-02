#include <bits/stdc++.h> 
using namespace std;
#define N 100001

int n;
pair<int, int> a[N];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
}
void solve(){
    int res = 0;
    int last = -1;
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i <= n; i++)
        if(a[i].first > last){
            res++;
            last = a[i].second;
        }
    cout << res << endl;

}
int main(){
    input();
    solve();
    return 0;
}