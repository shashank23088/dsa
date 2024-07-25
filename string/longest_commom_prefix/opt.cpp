// T(N) : O(NlogN)
// S(N) : O(1)
// M  : longest common prefix size
#include <bits/stdc++.h>

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    
    string res = "";
    int n = strs.size();

    if (n == 0) {
        return res;
    }

    if (n == 1) {
        return strs[0];
    }

    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last  = strs[n - 1];
    int m = min(first.size(), last.size());

    for (int i = 0; i < m; i++) {
        if (first[i] != last[i]) {
            break;
        }
        res.push_back(first[i]);
    }

    return res;
}


int main() {
    vector<string> strs = {"abab","aba","abc"};
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}