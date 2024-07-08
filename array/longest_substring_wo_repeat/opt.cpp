// T(N) = O(N)
// S(N) = O(1)    // because max can be 256 chars

#include <bits/stdc++.h>

using namespace std;

// don't do left++ everytime
// directly jump left to previously seen repeated character position

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int longest_length = 0;
    int left = 0;
    int right = 0;
    map<int, int> keys;

    while(left <= right && right < n) {
        // char not in map or outside of current subset range
        if (keys.find(s[right]) == keys.end() || keys[s[right]] < left) {    // map.find is O(1) average case
            longest_length = max(longest_length, right - left + 1);
        }

        // locate last pos of duplicate char and move left to 1 pos right of that char
        else {
            left = keys[s[right]] + 1;
        }

        // update the map
        keys[s[right]] = right;
        right++;
    }

    return longest_length;
}


int main () {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}