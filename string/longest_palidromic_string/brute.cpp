// T(N) : O(N^3)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


bool checkPalindrome(string s) {

    int n = s.size();
    if (n == 0 || n == 1) {
        return true;
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}


string longestPalindrome(string s) {
    
    int n = s.size();
    int max_len = INT_MIN;
    string res = "";
    
    for (int i = 0; i < n; i++) {
        int start_idx = i;
        int end_idx = i;

        while (end_idx < n) {
            int substr_len = end_idx - start_idx + 1;
            string substring = s.substr(start_idx, substr_len);
            if (checkPalindrome(substring) && substr_len > max_len) {
                res = substring;
                max_len = substr_len;
            }
            end_idx++;
        }
    }

    return res;
}


int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;

    return 0;
}