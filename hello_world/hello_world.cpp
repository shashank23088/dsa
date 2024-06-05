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

int main()
{
    string c = "*";
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        doSomething(c, n);
    }

    return 0;
}