// T(N) : O(N)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


int findMaxConsecutiveOnes(vector<int>& nums) {
    
    int count = 0;
    int max_count = 0;
    for (auto itr : nums) {
        if (itr == 1) {
            count++;
            max_count = max(max_count, count);
        }

        else {
            count = 0;
        }
    }

    return max_count;
}


int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}