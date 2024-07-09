// T(N) = O(N^2)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


int singleNumber(vector<int>& nums) {

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                freq++;
            }
        }
        if (freq != 2) {
            return nums[i];
        }
    }
    return INT_MIN;
}


int main() {
    vector<int> nums = {2, 2, 1};
    cout << singleNumber(nums) << endl;

    return 0;
} 