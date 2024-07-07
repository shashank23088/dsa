// T(N) = O(N) + O(NlogN)   // logN for an ordered map
// S(N) = O(1)/ O(N) [for index problem]
// Greedy approach (not optimal if we've to return indices)
// Optimal for yes/ no version, optimal for indices is the 'better' version
// Two pointer approach
// won't work in the case of [3, 3] if we've to return indices

#include <bits/stdc++.h>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> temp;   
    map<int, int> keys;

    for (int i = 0; i < n; i++) {
        keys[nums[i]] = i;
    }

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        // cout << left << " " << right << endl;
        int elements_sum = nums[left] + nums[right];
        if (elements_sum == target) {
            temp.insert(temp.end(), {keys[nums[left]], keys[nums[right]]});
            return temp;
        }
        if (elements_sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    temp.insert(temp.end(), {-1, -1});
    return temp;

}


int main() {
    vector<int> nums = {2, 7, 11, 5};
    int target = 9;
    vector<int> results = twoSum(nums, target);
    cout << results[0] << " " << results[1] << endl;

    return 0;
}