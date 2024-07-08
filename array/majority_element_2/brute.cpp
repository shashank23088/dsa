// only 2 elements can be majority here at max
// T(N) = O(N2)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


vector<int> majorityElement(vector<int>& nums) {
    vector<int> majority_elements;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (majority_elements.size() == 2) {
            break;
        }
        if (majority_elements.empty() || majority_elements[0] != nums[i]) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
                if (count > n / 3) {
                    majority_elements.emplace_back(nums[i]);
                    break;
                }
            }
        }
    }

    return majority_elements;
}


int main () {
    vector<int> nums = {3, 2, 3};
    vector<int> majority_elements = majorityElement(nums);

    for (auto itr : majority_elements) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}