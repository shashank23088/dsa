// T(N) = O(e^N)
// S(N) = O(e^N)    // uses stack space

#include <bits/stdc++.h>

using namespace std;


bool is_valid(int i, int j, int m, int n) {

    if (i >= m || j >= n) {
        return 0;
    }
    return 1;
}


int recurseMatrix(int i, int j, int m, int n) {
    if (!is_valid(i, j, m, n)) {
        return 0;
    }
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    return recurseMatrix(i + 1, j, m, n) + recurseMatrix(i, j + 1, m, n);
}


int uniquePaths(int m, int n) {
    int i = 0;
    int j = 0;

    return recurseMatrix(i, j, m, n);
}


int main () {
    int m = 19;
    int n = 13;

    cout << uniquePaths(m, n) << endl;

    return 0;
}