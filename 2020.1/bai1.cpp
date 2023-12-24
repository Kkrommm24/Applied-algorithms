// Tìm số các dãy con tăng
#include <bits/stdc++.h>
using namespace std;
#define N 100001
#define M 1000001
int a[N];
int n;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

int main(){
    int cnt = 0;
    input();
    for (int i = 2; i <= n; i++) {
        if(a[i] > a[i-1] && a[i] > a[i + 1]) cnt++;
    }
    cout << cnt;
    return 0;
}