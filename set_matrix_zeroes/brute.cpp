// m x n matrix
// T(m, n) = O( (nxm)(n + m) + (n + m) ) == O(n3)

#include <bits/stdc++.h>

using namespace std;


void markRow(vector< vector<int> >& matrix, int i) {
    int n = matrix[0].size();
    for (int k = 0; k < n; k++) {
        if (matrix[i][k] != 0) {
            matrix[i][k] = -1;
        }
    }
}


void markColumn(vector< vector<int> >& matrix, int j) {
    int m = matrix.size();
    for (int l = 0; l < m; l++) {
        if (matrix[l][j] != 0) {
            matrix[l][j] = -1;
        }
    }
}


void setZeroes(vector< vector<int> >& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // vector< vector<int> > matrix_copy = matrix;    //using extra space (out-place)

    // approach without using extra space             // in-place
    // mark as -1 in places where you need to mark 1 as 0
    // then use extra for loop to replace -1 with 0    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {

                markRow(matrix, i);
                markColumn(matrix, j);
                
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
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