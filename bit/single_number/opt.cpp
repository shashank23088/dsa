// T(N) = O(N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


int singleNumber(vector<int>& nums) {

    int n = nums.size();
    int single_num = nums[0];

    for (int i = 1; i < n; i++) {
        single_num ^= nums[i];
    }

    return single_num;
}


int main() {
    vector<int> nums = {2, 1, 2, 4, 1};
    cout << singleNumber(nums) << endl;

    return 0;
} 