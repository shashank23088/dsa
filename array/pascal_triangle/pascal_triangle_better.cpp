#include <bits/stdc++.h>

using namespace std;


vector< vector<int> > generatePascalTriangle(int numRows) {
    vector< vector<int> > pascals_triangle;

    for (int i = 0; i < numRows; i++) {
        vector<int> temp(i + 1, 1);
        for (int j = 1; j < i; j++) {
            temp[j] = pascals_triangle[i - 1][j - 1] + pascals_triangle[i - 1][j];
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