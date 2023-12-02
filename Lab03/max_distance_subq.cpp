#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(vector<int>& positions, int distance, int C) {
    int count = 1;
    int lastPosition = positions[0];
    
    for (int i = 1; i < positions.size(); i++) {
        // cout << i << " " << lastPosition << '\n';
        if (positions[i] - lastPosition >= distance) {
            count++;
            lastPosition = positions[i];
        }
    }
    // cout << "count: " << count << '\n';
    return count >= C;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<int> positions(N);
        for (int i = 0; i < N; i++) {
            cin >> positions[i];
        }

        sort(positions.begin(), positions.end());

        int left = 0, right = positions[N - 1] - positions[0];
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // cout << "distance: " << mid << '\n';
            if (canPlace(positions, mid, C)) {
                result = mid;
                left = mid + 1;
                // cout << "left: " << left << " right: " << right << '\n';
            } else {
                right = mid - 1;
                // cout << "left: " << left << " right: " << right << '\n';
            }
        }

        cout << result << endl;
    }

    return 0;
}
