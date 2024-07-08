// T(N) = O(N2)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


pair<int, int> twoSum(vector<int>& arr, int target) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (arr[i] + arr[j] == target) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);

}


int main() {
    vector<int> arr = {2, 7, 11, 5};
    int target = 9;
    pair<int, int> result = twoSum(arr, target);
    cout << result.first << " " << result.second << endl;

    return 0;
}