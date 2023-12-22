#include <bits/stdc++.h>
using namespace std;

#define N 51

int a[N];
int n, A, B;
int T = 0;
int cnt = 0;
void input() {
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void Try(int v) {
    if (v > n) { 
        return;
    }  
    T = T + a[v];
    if (T >= A && T <= B) {
        cnt++;
        // cout << T << endl;
    }
    if (T <= B) {
        Try(v + 1);
    }
    
    T = T - a[v];
    Try(v + 1);
}


int main() {
    input();
    Try(1);
    cout << "Count: " << cnt << endl;
    return 0;
}
