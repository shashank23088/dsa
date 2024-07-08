#include <bits/stdc++.h>

using namespace std;


vector<int> generateRow(int numElements) {
    vector<int> row;
    long long result = 1;

    for (int i = 1; i <= numElements; i++) {
        row.emplace_back(result);
        result *= (numElements - i);
        result /= (i);
    }

    return row;
}


vector< vector<int> > generatePascalTriangle(int numRows) {
    vector< vector<int> > pascals_triangle;

    for (int i = 0; i < numRows; i++) {
        pascals_triangle.emplace_back(generateRow(i + 1));
    }

    return pascals_triangle;
}


int main () {
    int numRows = 8;

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