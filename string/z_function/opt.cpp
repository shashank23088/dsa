// needle in haystack
// T(N) : O(N)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


int strStr(string haystack, string needle) {
    
    int n = haystack.size();
    int n0 = needle.size();

    for (int i = 0; i <= n - n0; i++) {
        string substring = haystack.substr(i, n0);
        if (substring == needle) {
            return i;
        }
    }

    return -1;
}


int main() {
    string haystack = "lodakasadfeelsad";
    string needle = "sad";
    cout << strStr(haystack, needle) << endl;

    return 0;
}