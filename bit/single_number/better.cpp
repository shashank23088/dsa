// T(N) = O(Nlog(N/2 + 1)) + O(N)
// S(N) = O(N/2 + 1)

#include <bits/stdc++.h>

using namespace std;


int singleNumber(vector<int>& nums) {

    int n = nums.size();
    map<int, int> keys;

    for (auto itr : nums) {    // O(N)
        keys[itr]++;
    }

    for (auto itr : keys) {    // O(Nlog(N/2))
        if (itr.second != 2) {
            return itr.first;
        }
    }

    return INT_MIN;
}


int main() {
    vector<int> nums = {2, 2, 1};
    cout << singleNumber(nums) << endl;

    return 0;
} 