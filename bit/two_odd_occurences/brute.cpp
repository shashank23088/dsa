// T(N) = O(NlogM) + O(M)    // M = size of map = N/2 + 1
// S(N) = O(M)

#include <bits/stdc++.h>

using namespace std;


vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    map<int, int> keys;
    vector<long long int> two_odd_num;
    for (int i = 0; i < N; i++) {    // O(NlogM)
        keys[Arr[i]]++;
    }

    for (auto itr : keys) {    // O(M)
        if (itr.second & 1) {
            two_odd_num.emplace_back(itr.first);
        }
    }
    sort(two_odd_num.rbegin(), two_odd_num.rend());    // O(1)    [as only two elements to be sorted]
    return two_odd_num;

}


int main() {
    int N = 8;
    long long int Arr[N] = {4, 2, 4, 5, 2, 3, 3, 1};
    vector<long long int> two_odd_num = twoOddNum(Arr, N);

    for (auto itr : two_odd_num) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}