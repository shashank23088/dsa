#include <bits/stdc++.h>

using namespace std;

void doSomething(string c, int n) {

    for (int i = 0; i < n; i++) {
        // for (int j1 = 0; j1 < n - i - 1; j1++) {
        //     cout << " ";
        // }
        for (int j2 = 0; j2 < i + 1; j2++) {
            cout << "*";
        }
        // for (int j1 = 0; j1 < n - i - 1; j1++) {
        //     cout << " ";
        // }
        cout << endl;
    }

    for (int i = n; i > 0; i--) {
        // for (int j1 = 0; j1 < n - i; j1++) {
        //     cout << " ";
        // }
        for (int j2 = i - 1; j2 > 0; j2--) {
            cout << "*";
        }
        // for (int j1 = 0; j1 < n - i; j1++) {
        //     cout << " ";
        // }
        cout << endl;
    }
}

void printAllSubarrays(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k < j; k++) {
                cout << v[k] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    // string c = "*";
    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++) {
    //     int n;
    //     cin >> n;
    //     doSomething(c, n);
    // }

    vector<int> v = {1, 2, 3, 4, 5};
    printAllSubarrays(v);

    return 0;
}