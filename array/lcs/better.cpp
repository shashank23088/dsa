// T(N) = O(NlogN) + O(N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
        }

    sort(nums.begin(), nums.end());

    int lcs_length = 1;
    int count = 1;
    int first_element = nums[0];
    for (int i = 1; i < n; i++) {
        int second_element = nums[i];
        if (second_element == first_element) {
            continue;
        }
        if (second_element == first_element + 1) {
            count++; 
        }
        else {
            count = 1;
        }
        first_element = second_element;
        if (count > lcs_length) {
            lcs_length = count;
        }
    }

    return lcs_length;
}


int main() {
    vector<int> nums = {1, 2, 0, 1};
    cout << longestConsecutive(nums) << endl;

    return 0;
}