// T(N) = O(N^3)
// S(N) = O(2^N * N)

#include <bits/stdc++.h>

using namespace std;


void subsets_recursive(vector<int>& temp, vector<int> nums, int idx, vector< vector<int> >& subsets) {
    if (idx >= nums.size()) {
        subsets.emplace_back(temp);
        return;
    }

    // element pick condition
    temp.emplace_back(nums[idx]);
    subsets_recursive(temp, nums, idx + 1, subsets);

    // element not pick condition
    temp.pop_back();
    subsets_recursive(temp, nums, idx + 1, subsets);
    
}


vector< vector<int> > subsets(vector<int>& nums) {
    vector< vector<int> > subsets;
    int idx = 0;
    vector<int> temp;
    subsets_recursive(temp, nums, idx, subsets);

    return subsets;
}


int main() {
    vector<int> nums = {1, 2, 3};
    vector< vector<int> > power_set = subsets(nums);
    for (auto itr : power_set) {
        for (auto it : itr) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}