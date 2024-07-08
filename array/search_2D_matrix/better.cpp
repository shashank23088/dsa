// T(N) = O(N) + log(M) // bcz binary search only once
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


bool searchMatrix(vector< vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    for (auto itr : matrix) {
        if (itr[n - 1] >= target) {

            // for (int i = n - 1; i >= 0; i--) {
            //     if (itr[i] == target) {
            //         return true;
            //     }
            // }

            int low = 0;
            int high = n - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if ( (itr[mid] == target) || (itr[low] == target) || (itr[high] == target) ) {
                    return true;
                }
                if (target > itr[mid]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
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