// optimal for arrays with negative values
// T(N): O(NlogN)    // logN for ordered map    // N for unordered map, then O(N2)
// S(N): O(N)

#include <bits/stdc++.h>

using namespace std;


int maxLen(vector<int>& arr, int n) {
    int target = 0;
    int longest_len = 0;
    int prefix_sum = 0;
    map<int, int> keys;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        if (prefix_sum == 0) {
            longest_len = max(longest_len, i + 1);
            continue;
        }
        int rem_sum = prefix_sum - target;
        if (keys.find(rem_sum) != keys.end()) {
            int candidate_subarr_len = i - keys[rem_sum];
            longest_len = max(longest_len, candidate_subarr_len);
        }
        if (keys.find(prefix_sum) != keys.end()) {
            continue;
        }
        keys[prefix_sum] = i; 
    }

    return longest_len;
}


int main() {
    vector<int> arr = {-1, 1, -1, 1}; 
    int n = arr.size();
    cout << maxLen(arr, n) << endl;

    return 0;
}