#include <bits/stdc++.h>

using namespace std;


int majorityElement(vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i; j < n; j++) {
            if (v[j] == v[i]) {
                count += 1;
            }
        }
        if (count > n / 2) {
            return v[i];
        }
    }

    return -1;
}


int main() {
    vector<int> v = {3,2,3};

    cout << majorityElement(v) << endl;

    return 0;
}