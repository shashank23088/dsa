// T(N) = O(log2(N))
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


double myPow(double x, int n) {

    bool is_neg = false;
    long absN = n > 0 ? n : -(long)n;    // conversion to long because of overflow

    if (absN == 0) {
        return 1;
    }
    
    double result = myPow(x, absN / 2);
    double final_result;
    if (absN % 2 == 0) {
        final_result = result * result;
    }

    else {
        final_result = x * result * result;
    }

    return n > 0 ? final_result : (1.0 / final_result);

}


int main() {
    double x = 2.00000;
    int n = -2;
    cout << myPow(x, n) << endl;

    return 0;
}