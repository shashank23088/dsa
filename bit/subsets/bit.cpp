// T(N) = O(2^N * N)
// S(N) = O(2^N * N)

#include <bits/stdc++.h>

using namespace std;


vector< vector<int> > subsets(vector<int>& nums) {
    int n = nums.size();
    int n_subsets = 1 << n;    // 2 ^ n
    vector< vector<int> > power_set;

    for (int i = 0; i < n_subsets; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {    // check if jth bit is set or not
                temp.emplace_back(nums[j]);
            }
        }
        power_set.emplace_back(temp);
    }

    return power_set;
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