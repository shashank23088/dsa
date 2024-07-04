// T(N) = O((N2 - N) / 2) + O(N * N/2) = O(N2)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


void rotateMatrix(vector< vector<int> >& matrix) {

    int n = matrix.size();

    // traversing lower triangle of square matrix
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

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