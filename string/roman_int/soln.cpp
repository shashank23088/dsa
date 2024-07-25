// T(N) : O(N)
// S(N) : O(1)
#include <bits/stdc++.h>

using namespace std;


int romanToInt(string s) {
    
    map<char, int> keys;
    vector<int> nums = {1, 5, 10, 50, 100, 500, 1000};
    vector<char> strs = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int n_nums = nums.size();
    int n_s = s.size();
    int result = 0;

    for (int i = 0; i < n_nums; i++) {
        keys[strs[i]] = nums[i];
    }

    int i = 0;
    for (; i < n_s - 1; i++) {
        if (keys[s[i + 1]] > keys[s[i]]) {
            result += keys[s[i + 1]] - keys[s[i]];
            i++;
        }
        else {
            result += keys[s[i]];
        }
    }

    if (i == n_s - 1) {
        result += keys[s[i]];
    }

    return result;
}


int main() {
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;

    return 0;
}