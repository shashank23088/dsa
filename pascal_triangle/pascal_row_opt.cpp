// T(n): O(r)
// S(n): O(1)

#include <bits/stdc++.h>

using namespace std;


void printPascalRow(int r) {
    int result = 1;

    for (int i = 1; i <= r; i++) {
        cout << result << " ";
        result *= (r - i);
        result /= (i);
    }

    cout << endl;
}


int main() {
    int r = 5;

    printPascalRow(r);

    return 0;
}