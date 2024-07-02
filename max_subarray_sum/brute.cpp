#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, int> maxSubarrSum(vector<int>& v) {
    vector<int> max_subarr;
    int max_sum = INT_MIN;
    int n = v.size();

    for (int s = 0; s < n; s++) {
        for (int e = s; e < n; e++) {
            int sum = 0;
            vector<int> subarr;
            for (int i = s; i < e; i++) {
                sum += v[i];
                subarr.emplace_back(v[i]);
            }
            if (sum > max_sum) {
                max_sum = sum;
                max_subarr = subarr;
            }
        }
    }
    
    return make_pair(max_subarr, max_sum);
}

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    pair< vector<int>, int > p;
    p = maxSubarrSum(v);
    for (auto itr : p.first) {
        cout << itr << " ";
    }
    cout << endl;
    cout << p.second << endl;

    return 0;
}