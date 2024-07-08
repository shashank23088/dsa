// T(r) = O(r3)
// S(r) = O(1)

#include <bits/stdc++.h>

using namespace std;


float returnNCR(int n, int r) {
    int result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}


vector< vector<int> > generatePascalTriangle(int numRows) {
    vector< vector<int> > pascals_triangle;

    for (int i = 0; i < numRows; i++) {
        vector<int> temp;
        for (int j = 0; j <= i; j++) {
            temp.emplace_back(returnNCR(i, j));
        }
        pascals_triangle.emplace_back(temp);
    }

    return pascals_triangle;
}


int main () {
    int numRows = 5;

    vector< vector<int> > pascals_triangle = generatePascalTriangle(numRows);
    for (auto itr : pascals_triangle) {
        for (auto it : itr) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}