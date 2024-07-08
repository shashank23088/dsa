// T(N) = O(M - 1) or O(N - 1)    // use (m + n - 2)C(m - 1) or (m + n - 2)C(n - 1) 
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


int nCr(int n, int r) {
    double result = 1;
    for (int i = 1; i <= r; i++) {
        result = result * (n - r + i) / i;
    }
    return result;
}


int uniquePaths(int m, int n) {
    // int i = 0;
    // int j = 0;

    return nCr(m + n - 2, m - 1);
}


int main () {
    int m = 53;
    int n = 4;

    cout << uniquePaths(m, n) << endl;

    return 0;
}