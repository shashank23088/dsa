// only 2 elements can be majority here at max
// T(N) = O(N)
// S(N) = O(N)

#include <bits/stdc++.h>

using namespace std;


vector<int> majorityElement(vector<int>& nums) {
    vector<int> majority_elements;
    map<int, int> freq;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (majority_elements.size() == 2) {
            break;
        }
        freq[nums[i]]++;
        if ((majority_elements.empty() || majority_elements[0] != nums[i]) && freq[nums[i]] > n / 3) {
            majority_elements.emplace_back(nums[i]);
        }
    }

    return majority_elements;
}


int main () {
    vector<int> nums = {2, 2};
    vector<int> majority_elements = majorityElement(nums);

    for (auto itr : majority_elements) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}