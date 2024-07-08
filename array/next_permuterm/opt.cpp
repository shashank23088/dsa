// 1. find breakpoint (a[i] < a[i + 1]) [bcz longest prefix match]
// 2. start from the breakpoint, and try to swap with smallest no. > a[i]
// 3. sort the remaining no.'s in increasing order
// T(n): O(3n)
// S(n): O(1)

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


void returnNextPermutation(vector<int>& arr) {
    int n = arr.size();

    // 1. breakpoint
    int i = n - 1;
    bool breakpoint_found = false;
    for (; i > 0; i--) {
        if (arr[i] > arr[i - 1]) {
            i = i - 1;
            breakpoint_found = true;
            break;
        }
    } 

    // handle edge case where all elements in descending order
    if (!breakpoint_found) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // cout << "breakpoint at " << i << ": " << arr[i] << endl;  

    // 2. swap breakpoint with smallest greater no.
    //int curr_greater_idx = -1;
    // int curr_greater_val = INT_MAX;
    // NO NEED (AS WE'VE ALREADY FOUND THE BREAKPOINT, AND ALL THE ELEMENTS ARE GREATER THERE)
    // for (int j = i + 1; j < n; j++) {
    //     if ( (arr[j] > arr[i]) && (arr[j] < curr_greater_val) ) {
    //         curr_greater_idx = j;
    //         curr_greater_val = arr[j];
    //     }
    // }
    int j = n - 1;
    for (; j > i; j--) {
        if (arr[j] > arr[i]) {
            break;
        }
    }

    // cout << "greatest element > arr[i]: " << arr[curr_greater_idx] << endl;
    swap(arr[j], arr[i]);
    // int temp = arr[curr_greater_idx];
    // arr[curr_greater_idx] = arr[i];
    // arr[i] = temp;

    // 3. sort remaining elements
    reverse(arr.begin() + i + 1, arr.end());

}


int main() {
    // vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    vector<int> arr = {1, 2, 3};
    returnNextPermutation(arr);
    
    for (auto itr : arr) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}