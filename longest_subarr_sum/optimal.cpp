// only optimal for non-negative arrays
// T(N): O(2N)
// S(N): O(1)

#include <bits/stdc++.h>

using namespace std;


int maxLen(vector<int>& arr, int n) {

    if (arr.size() == 0) {
        return 0;
    }

    int target = 6;
    int longest_len = 0;
    int curr_sum = 0;
    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i++) {    // O(N)

        curr_sum += arr[i];

        while (left <= right && curr_sum > target) {    // O(N) : overall
            curr_sum -= arr[left];
            left++;
        }

        if (curr_sum == target) {
            longest_len = max(longest_len, right - left + 1);
        }

        right++;

    }

    return longest_len;
}


int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3}; 
    int n = arr.size();
    cout << maxLen(arr, n) << endl;

    return 0;
}