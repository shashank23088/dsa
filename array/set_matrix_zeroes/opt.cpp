// m x n matrix
// T(m, n) = O( 2 x n x m )
// S(m, n) = O(1) [in-place algorithm]
// 1. take row[0] and col[0] as rows_to_set and cols_to_set [take col0 = 1 variable for cols_to_set[0]]
// 2. set all rows and cols to '0' whenever 0 is encountered
// 3. solve the middle part first by checking either the row or col set
// 4. then solve the first row
// 5. at last solve the first column

#include <bits/stdc++.h>

using namespace std;


void setZeroes(vector< vector<int> >& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    
    // marking all matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if (j != 0) {
                    matrix[0][j] = 0;
                }
                else {
                    col0 = 0;
                }
            }
        }
    }
    
    // solving middle elements
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if ( (matrix[i][j] != 0) && (!matrix[i][0] || !matrix[0][j]) ) {
                matrix[i][j] = 0;
            }
        }
    }

    // solving the first row
    if (!matrix[0][0]) {
        for (int j = 1; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // solving the first column
    if (!col0) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}


int main() {
    vector< vector<int> > matrix = { {1,1,1},{1,0,1},{1,1,1} };

    for (auto itr : matrix) {
        for (auto it : itr) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    setZeroes(matrix);
    cout << endl;

    for (auto itr : matrix) {
        for (auto it : itr) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}