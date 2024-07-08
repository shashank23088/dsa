// T(N, M) = O(N + M)
// S(N, M) = O(N + M)

#include <bits/stdc++.h>

using namespace std;


void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> merged_array;
    int i = 0; 
    int j = 0;

    while(i < m && j < n) {

        int add_num = -1;
        if (nums1[i] <= nums2[j]) {
            add_num = nums1[i];
            i += 1;
        }

        else {
            add_num = nums2[j];
            j += 1;
        }

        merged_array.emplace_back(add_num);
    }

    

    while(i < m) {
        merged_array.emplace_back(nums1[i]);
        i += 1;
    }

    while(j < n) {
        merged_array.emplace_back(nums2[j]);
        j += 1;
    }

    nums1 = merged_array;
}


int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};
    int m = 3; 
    int n = 3; 

    mergeArrays(nums1, m, nums2, n);

    for (auto itr : nums1) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}