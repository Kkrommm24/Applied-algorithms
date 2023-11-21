#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Hàm xây dựng cây segment tree
void buildSegmentTree(const vector<int>& arr, vector<int>& segmentTree, int low, int high, int pos) {
    if (low == high) {
        segmentTree[pos] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    buildSegmentTree(arr, segmentTree, low, mid, 2 * pos + 1);
    buildSegmentTree(arr, segmentTree, mid + 1, high, 2 * pos + 2);

    segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

// Hàm truy vấn giá trị nhỏ nhất trong một đoạn
int query(const vector<int>& segmentTree, int qlow, int qhigh, int low, int high, int pos) {
    if (qlow <= low && qhigh >= high) {
        return segmentTree[pos];
    }

    if (qlow > high || qhigh < low) {
        return INT_MAX;
    }

    int mid = (low + high) / 2;
    return min(query(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1),
               query(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Tính kích thước của cây segment tree
    int treeSize = 2 * n - 1;
    vector<int> segmentTree(treeSize);

    // Xây dựng cây segment tree
    buildSegmentTree(arr, segmentTree, 0, n - 1, 0);

    int m;
    cin >> m;

    int totalQ = 0;

    for (int i = 0; i < m; ++i) {
        int qlow, qhigh;
        cin >> qlow >> qhigh;

        // Truy vấn và tính tổng
        totalQ += query(segmentTree, qlow, qhigh, 0, n - 1, 0);
    }

    cout << totalQ << endl;

    return 0;
}
