#include <bits/stdc++.h>

using namespace std;


vector<int> subsetSums(vector<int> arr, int n) {
    


}


int main() {
    vector<int> arr = {2, 3};
    int n = arr.size();

    vector<int> subset_sums = subsetSums(arr, n);

    for (auto itr : subset_sums) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}