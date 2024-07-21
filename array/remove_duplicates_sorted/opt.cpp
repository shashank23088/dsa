// T(N) : O(N)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


// return #unique elements in nums
// inplace
int removeDuplicates(vector<int>& nums) {

    int n = nums.size();
    if (n < 2) {
        return n;
    }

    int i = 0; 
    int j = i + 1;

    while (j < n) {
        if (nums[j] != nums[i]) {
            nums[i + 1] = nums[j];
            i++;
        }
        j++;
    }

    return i + 1;
}


int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums) << endl;

    return 0;
}