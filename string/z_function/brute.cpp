// needle in haystack
// T(N) : O(MN)    // M : needle.size(), N : haystack.size()
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


int strStr(string haystack, string needle) {
    
    int n = haystack.size();
    int n0 = needle.size();

    int itr = 1;
    for (int i = 0; i <= n - n0; i++) {
    
        int start_idx = i;
        int end_idx = i + n0 - 1;
        int needle_idx = 0;
        bool found = true;
        for (int j = start_idx; j <= end_idx; j++) {
            if (haystack[j] != needle[needle_idx]) {
                found = false;
                break;
            }
            needle_idx++;
        }

        if (found) {
            return start_idx;
        }
        itr++;
    }

    return -1;
}


int main() {
    string haystack = "lodakasadfeelsad";
    string needle = "sad";
    cout << strStr(haystack, needle) << endl;

    return 0;
}