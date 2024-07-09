// T(dividend, divisor) = O(dividend)

#include <bits/stdc++.h>

using namespace std;


int divide(int dividend, int divisor) {
    bool is_neg = false;
    int quotient = 0;
    long current_sum = 0;

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
    divisor = abs(divisor);
    dividend = abs(dividend);

    while ((current_sum + divisor) <= dividend) {
        current_sum += divisor;
        quotient++;
    }
    
    if (is_neg) {
        quotient = -quotient;
    }

    return quotient;
}


int main() {
    int dividend = INT_MAX;
    int divisor = -1;
    cout << divide(dividend, divisor) << endl;

    return 0;
}