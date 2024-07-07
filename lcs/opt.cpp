// T(N) = O(2N) + O(N)
// S(N) = O(N)
// assuming unordered set is taking O(1), otherwise 'better' soln is optimal

#include <bits/stdc++.h>

using namespace std;


int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    unordered_set<int> nums_set;
    for (auto itr : nums) {
        nums_set.insert(itr);    // O(1)
    }

    int lcs_length = 1;
    for (auto itr : nums_set) {    // O(2N) : not counting while loop as O(N), as we're only iterating with candidate elements
        int count = 1;
        if (nums_set.find(itr - 1) != nums_set.end()) {
            count = 1;
            continue;
        }
        
        else {
            int curr_element = itr;
            while (nums_set.find(curr_element + 1) != nums_set.end()) {
                curr_element++;
                count++;
            }
            lcs_length = max(lcs_length, count);
        }
    }

    return lcs_length;
}


int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(nums) << endl;

    return 0;
}