// DNF algo
// T(N) = O(N)    // reduced from 2N
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


void sort_colors(vector<int>& nums) {

    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    for (int i = 0; i < n; i++) {
        if (mid > high) {
            return;
        }
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else if (nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high--;
        }
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