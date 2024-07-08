// given R, C; give pascals_triangle(R, C)
// pascals_triangle(R, C) = (R-1)c(C-1)
// use shortcut: 10C3 = 10 x 9 x 8 / 3 x 2 x 1
// divide in format: 10/1 X 9/2 x 8/3
// T(n): O(n)
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

int returnPascalElement(int r, int c) {

    return findNCR(r - 1, c - 1);
}


int main() {
    int r = 3;
    int c = 2;

    cout << returnPascalElement(r, c) << endl;

    return 0;
}