// naive: sort -> check a[i] == a[i + 1] ? if yes, return a[i]    // T(N): O(NlogN); S(N): O(1)
// better: use hash map to count freq of each element    // T(N): O(N); S(N): O(N)
// optimal: LL-cycle method
// T(N) = O(N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;

    do { 
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}


int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << findDuplicate(nums) << endl;

    return 0;
}