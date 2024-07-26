// T(N) : O(N)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


int myAtoi(string s) {
    
    double res = 0;
    int i = 0;
    int n = s.size();
    bool is_neg = false;

    if (n == 0) {
        return 0;
    }

    // ignore leading whitespaces
    while (s[i] == ' ' && i < n) {
        i++;
        if (i == n) {
            return res;
        }
    }

    // check sign
    if (s[i] == '-') {
        is_neg = true;
        i++;
    }

    else if (s[i] == '+') {
        i++;
    }

    if (i == n) {
        return res;
    }

    while (s[i] == '0' && i < n) {
        i++;
        if (i == n) {
            return res; 
        }
    }

    while ((int)s[i] - 48 >= 0 && (int)s[i] - 48 <= 9 && i < n) {
        res = res*10 + ((int)s[i] - 48);
        if (is_neg && res > (long)INT_MAX + 1) {
            return INT_MIN;
        }

        if (!is_neg && res > INT_MAX) {
            return INT_MAX;
        }
        i++;
    }

    if (is_neg) {
        res = -res;
    }

    return res;

}


int main() {
    string s = "   -042";
    cout << myAtoi(s) << endl;

    return 0;
}