// only 2 elements can be majority here at max
// T(N) = O(2N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> majority_elements;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < n; i++) {
        if (count1 == 0 && nums[i] != ele2) {
            count1 = 1;
            ele1 = nums[i];
        }
        else if (count2 == 0 && nums[i] != ele1) {
            count2 = 1;
            ele2 = nums[i];
        }

        else if (nums[i] == ele1) {
            count1++;
        }
        else if (nums[i] == ele2) {
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == ele1) {
            cnt1++;
        }
        else if (nums[i] == ele2) {
            cnt2++;
        }
    }

    if (cnt1 > n / 3) {
        majority_elements.emplace_back(ele1);
    }
    if (cnt2 > n / 3) {
        majority_elements.emplace_back(ele2);
    }

    return majority_elements;
}


int main () {
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> majority_elements = majorityElement(nums);

    for (auto itr : majority_elements) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}