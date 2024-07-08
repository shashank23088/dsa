// in-place sorting
// use merge sort for brute approach
// T(N) = O(2N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


void sort_colors(vector<int>& nums) {
    int n = nums.size();
    int zero = 0;
    int one = 0;
    int two = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zero++;
        }
        else if (nums[i] == 1) {
            one++;
        }
        else if (nums[i] == 2) {
            two++;
        }
    }

    int i = 0;
    for (int j = 0; j < zero; j++) {
        nums[i] = 0;
        i += 1;
    }
    for (int j = 0; j < one; j++) {
        nums[i] = 1;
        i += 1;
    }
    for (int j = 0; j < two; j++) {
        nums[i] = 2;
        i += 1;
    }

}


int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sort_colors(nums);

    for (auto itr : nums) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}