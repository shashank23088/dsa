// T(N) = O(N2)
// S(N) = O(N2)

#include <bits/stdc++.h>

using namespace std;


void rotateMatrix(vector< vector<int> >& matrix) {

    int n = matrix.size();
    vector< vector<int> > rotated_matrix;

    for (int i = 0; i < n; i++) {
        vector<int> temp(n, 0);
        rotated_matrix.emplace_back(temp);
    }

    // traversing lower triangle of square matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated_matrix[j][i] = matrix[n - 1 - i][j];
        }
    }

    matrix = rotated_matrix;

}


int main() {
    vector< vector<int> > matrix = {{1,2,3},{4,5,6},{7,8,9}};

    rotateMatrix(matrix);

    for (auto itr : matrix) {
        for (auto it : itr) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}