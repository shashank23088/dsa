#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor) {

    int is_neg = 0;
    int quotient = 0;

    if (dividend > INT_MAX) {
        cout << "true" << endl;
        return INT_MAX;
    }
    if (dividend < INT_MIN) {
        cout << "true" << endl;
        return INT_MIN;
    }

    if ((dividend < 0 || divisor < 0) && !(dividend < 0 && divisor < 0)) {
        is_neg = 1;
    }
    divisor = abs(divisor);
    dividend = abs(dividend);

    while(dividend >= divisor) {
        cout << dividend << " " << divisor << endl;
        dividend = dividend - divisor;
        quotient++;
    }

    if (is_neg) {
        quotient = -quotient;
    }

    return quotient;
}


int main() {
    cout << divide(-2147483648, -1) << endl;

    return 0;
}