// T(N) : O(NlogN) + O(N^2)
// S(N) : O(#triplets)

#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    
    int n = nums.size();
    vector< vector<int> > triplets;

    if (n < 3) {
        return triplets;
    }

    int i = 0; 

    sort(nums.begin(), nums.end());    // O(NlogN)

    for (int i = 0; i < n - 2; i++)  {    // O(N^2)
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;
        while (j < k) {

            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
                continue;
            }

            if (sum > 0) {
                k--;
                continue;
            }

            vector<int> temp = {nums[i], nums[j], nums[k]};
            triplets.emplace_back(temp);
            j++;
            k--;

            while (j < k && nums[j] == nums[j - 1]) {
                j++;
            }

            while (j < k && nums[k] == nums[k + 1]) {
                k--;
            }

        }

    }

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