#include <bits/stdc++.h>

using namespace std;

int maxSubarrSum(vector<int>& v) {
    // vector<int> max_subarr;
    int max_sum = INT_MIN;
    int n = v.size();

    for (int s = 0; s < n; s++) {
        int prev_sum = 0;
        for (int e = s; e < n; e++) {
            // vector<int> subarr;
            prev_sum += v[e];
            // subarr.emplace_back(v[e]);
            
            if (prev_sum > max_sum) {
                max_sum = prev_sum;
                // max_subarr = subarr;
            }
        }
    }
    
    // return make_pair(max_subarr, max_sum);
    return max_sum;
}

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    // pair< vector<int>, int > p;
    // p = maxSubarrSum(v);
    // for (auto itr : p.first) {
    //     cout << itr << " ";
    // }
    // cout << endl;
    // cout << p.second << endl;
    cout << maxSubarrSum(v) << endl;

    return 0;
}