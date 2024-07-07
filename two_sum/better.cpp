// T(N) = O(NlogN)   // logN for an ordered map
// S(N) = O(N)

#include <bits/stdc++.h>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> temp;
    map<int, int> keys;

    for(int i = 0; i < n; i++) {    // O(N)

        if (keys.find(target - nums[i]) != keys.end()) {    // O(logN)
            temp.insert(temp.end(), {keys[target - nums[i]], i});
            return temp;
        }

        else {
            keys[nums[i]] = i; 
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