#include <bits/stdc++.h>

using namespace std;


int MaximumFinal(vector<int>& arr) {

    int result = 1;
    if (arr.size() == 0) {
        return 0;
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++) {
        result = min(result + 1, arr[i]);
    }

    return result;
}


int main() {
    // vector<int> arr = {3, 1, 3, 4};
    // vector<int> arr = {1, 3, 2, 2};
    vector<int> arr = {3, 2, 3, 5};
    cout << MaximumFinal(arr) << endl;

    return 0;
}