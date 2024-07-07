// T(N) = O(2N)    // O(N) [for left ptr] + O(N) [for right ptr]
// S(N) = O(1)    // because max can be 256 chars

#include <bits/stdc++.h>

using namespace std;


int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int longest_length = 0;
    int left = 0;
    int right = 0;
    set<int> keys;

    while(left <= right && right < n) {
        if (keys.find(s[right]) == keys.end()) {
            longest_length = max(longest_length, right - left + 1);
        }

        else {
            while(left <= right && keys.find(s[right]) != keys.end()) {
                keys.erase(s[left]);
                left++;
            }
        }

        keys.emplace(s[right]);
        right++;
    }

    return longest_length;
}


int main () {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}