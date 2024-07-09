// T(dividend) = O(log2dividend) [log base2 dividend]
// inner while loop is O(32) constant
// S(dividend) = O(1)

#include <bits/stdc++.h>

using namespace std;


int divide(int dividend, int divisor) {
    bool is_neg = false;
    long quotient = 0;

    // check overflow
    if ((dividend >= INT_MAX && divisor == 1) || (dividend <= INT_MIN && divisor == -1)) {
        return INT_MAX;
    }

    // check underflow
    if (dividend <= INT_MIN && divisor == 1) {
        return INT_MIN;
    }

    if (dividend >= INT_MAX && divisor == -1) {
        return INT_MIN + 1;
    }

    if ((dividend < 0 || divisor < 0) && !(dividend < 0 && divisor < 0)) {
        is_neg = true;
    }
    long d = abs((long)divisor);
    long n = abs((long)dividend);

    while (n >= d) {
        int i = 0;
        while ((d << i+1) <= n) {    // check biggest i : 3x2^i <= dividend
            i++;
        }
        n -= (d << i);    // reduce dividend by divisor of biggest power of 2
        quotient += (1 << i);            // increment quotient with number of divisors substracted
    }
    
    if (is_neg) {
        quotient = -quotient;
    }

    return quotient;
}


int main() {
    int dividend = INT_MAX;
    int divisor = 2;
    cout << divide(dividend, divisor) << endl;

    return 0;
}