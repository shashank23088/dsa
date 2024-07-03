#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> arr = {1, 2, 3};
    next_permutation(arr.begin(), arr.end());
    
    for (auto itr : arr) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}