// T(N, M) = O(min(N, M)) + O(NlogN + MlogM)
// S(N, M) = O(1)

#include <bits/stdc++.h>

using namespace std;


void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = 0;

    while (i >= 0 && j < n) {
        if (nums1[i] > nums2[j]) {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        }

        else {
            break;
        } 
    }
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());
    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[i - m];
    }
}


int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
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