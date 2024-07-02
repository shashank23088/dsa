#include <bits/stdc++.h>

using namespace std;

pair<pair<int, int>, int> maxSubarrSum(vector<int>& v) {
    // vector<int> max_subarr;
    int max_sum = INT_MIN;
    int prev_sum = 0;
    int n = v.size();
    int s, ans_s, ans_e = -1;

    for (int i = 0; i < n; i++) {
        if (prev_sum == 0) {
            s = i;
        }

        prev_sum += v[i];

        if (prev_sum > max_sum) {
            ans_s = s;
            ans_e = i;
            max_sum = prev_sum;
        }

        if (prev_sum < 0) {
            prev_sum = 0;
        }
    
    }
    
    // return make_pair(max_subarr, max_sum);
    return make_pair(make_pair(ans_s, ans_e), max_sum);
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
    vector<int> subarr;
    pair<pair<int, int>, int> p = maxSubarrSum(v);
    for (int i = p.first.first; i <= p.first.second; i++) {
        subarr.emplace_back(v[i]);
    }

    for (auto itr : subarr) {
        cout << itr << " ";
    }
    cout << endl;

    cout <<  p.second << endl;

    return 0;
}