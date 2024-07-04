// T(N) = O(log2(NM)) // bcz binary search only once
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


bool searchMatrix(vector< vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Binary Search on hypothetical 1D array
    // 1D -> 2D: i -> (i/n, i%n)
    int low = 0;
    int high = m * n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int mid_val = matrix[mid / n][mid % n];
        int high_val = matrix[high / n][high % n];
        int low_val = matrix[low / n][low % n];
        if (target == mid_val || target == low_val || target == high_val) {
            return true;
        }
        if (target < mid_val) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return false;
}


int main() {
    vector< vector<int> > matrix = {{5, 6, 10, 11}, {22, 23, 29, 31}, {32, 100, 101, 201}};
    int target = 29;
    cout << searchMatrix(matrix, target) << endl;

    return 0;
}