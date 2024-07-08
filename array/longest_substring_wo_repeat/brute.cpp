// T(N) = O(N2)
// S(N) = O(N)

#include <bits/stdc++.h>

using namespace std;


int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int longest_length = 0;

    for (int i = 0; i < n; i++) {
        int current_length = 1;
        unordered_map<int, int> keys;
        keys[s[i]]++;
        for (int j = i + 1; j < n; j++) {
            if (keys.find(s[j]) == keys.end()) {
                keys[s[j]]++;
                current_length++;
            }
            else {
                break;
            }
        }

        longest_length = max(longest_length, current_length);
    }

    return longest_length;
}


int main () {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}