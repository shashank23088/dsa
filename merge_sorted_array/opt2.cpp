// T(N, M) = O(log2(N + M))*O(N + M)
// S(N, M) = O(1)
// Use GAP method (from Shell Sort)

#include <bits/stdc++.h>

using namespace std;


void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    // adding elements of nums2 to nums1
    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[i - m];
    }

    int gap = ceil((m + n) / 2.0);
    // int gap = ((m + n)/ 2) + ((m + n) % 2)
    int gap_one_count = 0;

    while (true) {
        if (gap == 1) {
            gap_one_count++;
        }
        if (gap_one_count == 2) {
            break;
        }
        int left = 0;
        int right = gap;
        while (right < m + n) {
            if (nums1[left] > nums1[right]) {
                swap(nums1[left], nums1[right]);
            }
            left++;
            right++;
        }
        gap = ceil(gap / 2.0);
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