// T(N) = O(NM)    // bcz only recursive calls from elements not in dp
// S(N) = O(NM)    // dp storing + stack from recursive calls -- 2MN

#include <bits/stdc++.h>

using namespace std;


int recurseMatrix(int i, int j, int m, int n, vector< vector<int> >& dp) {
    if (i >= m || j >= n) {
        return 0;
    }

    if (i == m - 1 && j == n - 1) {
        return 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    return dp[i][j] = recurseMatrix(i + 1, j, m, n, dp) + recurseMatrix(i, j + 1, m, n, dp);  
}


int uniquePaths(int m, int n) {
    int i = 0;
    int j = 0;

    vector< vector<int> > dp;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.emplace_back(-1);
        }
        dp.emplace_back(temp);
    }

    return recurseMatrix(i, j, m, n, dp);
}


int main () {
    int m = 2;
    int n = 3;

    cout << uniquePaths(m, n) << endl;

    return 0;
}