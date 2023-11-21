#include <bits/stdc++.h>
using namespace std;

#define N 1000000

long a[N], L, R, m;
long res;
long S;

long MaxRight(long a[], long mid, long R) {
    long sum = 0, maxRight = LONG_MIN;
    for (long i = mid + 1; i <= R; i++) {
        sum += a[i];
        maxRight = max(maxRight, sum);
    }
    return maxRight;
}

long MaxLeft(long a[], long L, long mid) {
    long sum = 0, maxLeft = LONG_MIN;
    for (long i = mid; i >= L; i--) {
        sum += a[i];
        maxLeft = max(maxLeft, sum);
    }
    return maxLeft;
}

long MaxSubSeq(long a[], long L, long R, long &start, long &end) {
    if (L == R) {
        start = end = L;
        return a[L];
    }

    m = (L + R) / 2;

    long startLeft, endLeft, startRight, endRight;

    long ML = MaxSubSeq(a, L, m, startLeft, endLeft);
    long MR = MaxSubSeq(a, m + 1, R, startRight, endRight);

    long maxRight = MaxRight(a, m, R);
    long maxLeft = MaxLeft(a, L, m);

    long M = max(maxRight + maxLeft, max(ML, MR));

    if (M == maxRight + maxLeft) {
        start = startLeft;
        end = endRight;
    } else if (M == ML) {
        start = startLeft;
        end = endLeft;
    } else {
        start = startRight;
        end = endRight;
    }

    return M;
}

int main() {
    long n;
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }

    L = 0;
    R = n - 1;

    long start, end;
    long result = MaxSubSeq(a, L, R, start, end);

    cout << result << endl;
    // cout << "Subarray with maximum sum: ";
    // for (long i = start; i <= end; i++) {
    //     cout << a[i] << " ";
    // }

    return 0;
}
