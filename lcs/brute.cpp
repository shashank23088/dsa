// T(N) = O(N3)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


int longestConsecutive(vector<int>& nums) {
    int n = nums.size();

    int lcs_length = 0;
    for (int i = 0; i < n; i++) {
        int l = 1;
        int curr_ele = nums[i];
        bool continue_run = false;
        do {
            continue_run = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == curr_ele + 1) {
                    l += 1;
                    curr_ele = nums[j];
                    continue_run = true;
                    break;
                }
            }
            if (l > lcs_length) {
                lcs_length = l;
            }
        } while(continue_run);
    }

    return lcs_length;
}


int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;

    return 0;
}