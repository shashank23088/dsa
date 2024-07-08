// m x n matrix
// T(m, n) = O( 2 x n x m )
// S(m, n) = O(m) + O(n)

#include <bits/stdc++.h>

using namespace std;


// void markRow(vector< vector<int> >& matrix, int i) {
//     int n = matrix[0].size();
//     for (int k = 0; k < n; k++) {
//         matrix[i][k] = 0;
//     }
// }


// void markColumn(vector< vector<int> >& matrix, int j) {
//     int m = matrix.size();
//     for (int l = 0; l < m; l++) {
//         matrix[l][j] = 0;
//     }
// }


void setZeroes(vector< vector<int> >& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rows_to_mark(m, 0);
    vector<int> cols_to_mark(n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rows_to_mark[i] = 1;
                cols_to_mark[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows_to_mark[i] || cols_to_mark[j]) {
                matrix[i][j] = 0;
            }
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