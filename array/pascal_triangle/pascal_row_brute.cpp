// T(n): O(n x r)
// S(n): O(1)

#include <bits/stdc++.h>

using namespace std;


float findNCR(int n, int r) {
    int result = 1;

    for (int i = 0; i < r; i++) {
        result = result * (n - i);
        result /= (i + 1);
    }
    
    return result;
}

void printPascalRow(int r) {

    for (int i = 1; i <= r; i++) {
        cout << findNCR(r - 1, i - 1) << " ";
    }
    cout << endl;
}


int main() {
    int r = 5;

    printPascalRow(r);

    return 0;
}