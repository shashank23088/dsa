// generate all subarrays
// find sum 0 subarrs
// find largest subarr
// T(N): O(N2)
// S(N): O(1)

#include <bits/stdc++.h>

using namespace std;


int maxLen(vector<int>& arr, int n) {
    int longest_len = 0;

    for (int i = 0; i < n; i++) {
        int curr_sum = 0;
        int curr_len = 0;
        for (int j = i; j < n; j++) {
            curr_sum += arr[j];
            curr_len += 1;
            if (curr_sum == 0) {
                longest_len = max(longest_len, curr_len);
            }
        }
    }

    return longest_len;
}


int main() {
    vector<int> arr = {1, 0, -4, 3, 1, 0}; 
    int n = arr.size();
    cout << maxLen(arr, n) << endl;

    return 0;
}