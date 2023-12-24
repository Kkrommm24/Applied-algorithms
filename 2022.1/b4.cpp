#include <iostream>
#include <vector>
#include <algorithm>
#define N 100001
using namespace std;

int a[N];
int n;
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

int maxSumNoAdjacent() {  
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return a[1];
    }  
    vector<int> dp(n, 0);
    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }
    return dp[n];
}

int main() {
    input();
    int result = maxSumNoAdjacent();
    cout << result << endl;
    
    return 0;
}
