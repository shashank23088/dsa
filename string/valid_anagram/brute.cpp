// T(N) : O(2NlogN)
// O(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


bool isAnagram(string s, string t) {
    int n = s.size();

    if (t.size() != n) {
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t) {
        return true;
    }

    return false;
}


int main() {
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t) << endl;

    return 0;
}