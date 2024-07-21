// T(N) : O(N^2*logM)    // M = #elements in hashmap
// S(N) : O(N) + O(2 * #triplets)

#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    
    int n = nums.size();
    set< vector<int> > triplets_set;

    for (int i = 0; i < n; i++) {    
        map<int, int> keys;

        for (int j = i + 1; j < n; j++) {

            int nums_k = -(nums[i] + nums[j]);
            if (keys.find(nums_k) != keys.end()) {
                vector<int> temp = {nums_k, nums[i], nums[j]};
                sort(temp.begin(), temp.end());
                triplets_set.insert(temp);
            }

            keys[nums[j]]++;

        }
    }

    vector< vector<int> > triplets(triplets_set.begin(), triplets_set.end());
    return triplets;

}


int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector< vector<int> > triplets = threeSum(nums);

    for (auto itr : triplets) {
        for (auto it : itr) {
            cout << it << " ";
        }
        cout << endl;
    } 

    return 0;
}