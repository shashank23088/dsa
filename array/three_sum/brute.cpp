// T(N) : O(N^3*log(#triplets))
// S(N) : O(2 * #triplets)

#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    
    int n = nums.size();
    set< vector<int> > triplets_set;

    for (int i = 0; i < n; i++) {    // O(n^3 * log(#triplets))
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    triplets_set.insert(temp);    // O(log(#triplets))
                }
            }
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