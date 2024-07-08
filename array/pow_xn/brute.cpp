// T(N) = O(N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


double myPow(double& x, int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}


int main() {
    double x = 2.00000;
    int n = 10;
    cout << myPow(x, n) << endl;

    return 0;
}