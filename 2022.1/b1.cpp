#include <bits/stdc++.h>
using namespace std;
#define N 100001
#define M 1000001
int a[N];
int n, k, m;

void input() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void count_subsequences() {
    int count = 0;

    for (int i = 1; i <= n - k + 1; i++) {  // Vòng lặp chính cho đầu mảng của dãy con
        int subset_sum = 0;
        for (int j = i; j < i + k; j++) {  // Vòng lặp con cho từng dãy con có k phần tử
            subset_sum += a[j];
        }
        if (subset_sum == m) {
            count++;
            cout << "Dãy con thỏa mãn tại vị trí " << i << ": ";
            for (int j = i; j < i + k; j++) {
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
    cout << "So luong day con thoa man la: " << count << endl;
}


int main(){
    input();
    count_subsequences();
    return 0;
}
