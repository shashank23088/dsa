#include <bits/stdc++.h>

using namespace std;

// now map doesn't contains indexes of prefix sums, it contains how many times that prefix sum came in the iteration
int subarraySum(vector<int>& nums, int k) {
    map<int, int> keys;
    int n = nums.size();
    int n_subarr = 0;
    int prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += nums[i];

        int rem_sum = prefix_sum - k;

        if (rem_sum == 0) {
            n_subarr += 1;    // the whole array from starting is also a subarray
        }    

        if (keys.find(rem_sum) != keys.end()) {
            n_subarr += keys[rem_sum];    // the subarr from keys[rem_sub] to i is subarray
        }

        keys[prefix_sum]++;
    }

    return n_subarr;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 3;
    cout << subarraySum(nums, target) << endl;

    return 0;
}