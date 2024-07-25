// T(N) : O(3N)
// O(N) : O(N)

#include <bits/stdc++.h>

using namespace std;


bool isAnagram(string s, string t) {
    int n = s.size();

    if (t.size() != n) {
        return false;
    }

    unordered_map<char, int> keys;
    for (int i = 0; i < n; i++) {
        keys[s[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (keys.find(t[i]) == keys.end()) {
            return false;
        }
        keys[t[i]]--;
    }

    for (int i = 0; i < n; i++) {
        if (keys[s[i]]) {
            return false;
        }
    }

    return true;
}


int main() {
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t) << endl;

    return 0;
}