// T(N) = O(N^3)
// S(N) = O(2^N)

#include <bits/stdc++.h>

using namespace std;


vector< vector<int> > subsets(vector<int>& nums) {
    int n = nums.size();
    vector< vector<int> > subsets = {{}};

    for (int i = 0; i < n; i++) {
        int start = i;
        int end = i;
        while (end < n) {
            vector<int> temp;
            for (int j = start; j <= end; j++) {
                temp.emplace_back(nums[j]);
            }
            end++;
            subsets.emplace_back(temp);
        }
    }

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