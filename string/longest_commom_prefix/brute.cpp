// T(N) : O(NM)
// S(N) : O(M)
// M  : longest common prefix size
#include <bits/stdc++.h>

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    
    string res = "";
    bool flag = true;
    int i = 0;
    int n = strs.size();

    if (n == 0) {
        return res;
    }

    if (n == 1) {
        return strs[0];
    }

    string curr_str = strs[0];
    if (curr_str.size() == 0) {
        return "";
    }

    while(flag) {

        char curr_char = strs[0][i];
        for (int j = 1; j < n; j++) {
            string curr_str = strs[j];
            
            if (i == curr_str.size()) {
                flag = false;
                break;
            }

            if (curr_str[i] != curr_char) {
                flag = false;
                break;
            }
        }

        if (flag) {
            res.push_back(curr_char);
            i++;
        }
    }

    return res;
}


int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}