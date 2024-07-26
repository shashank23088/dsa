// T(N) : O(N^2)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


string spreadPalindromeCheck(string s, int left, int right) {

    int n = s.size();

    while (left >= 0 && right < n && s[left] == s[right]) {
        right++;
        left--;
    }
    right--;
    left++;
    return s.substr(left, right - left + 1);
}


string longestPalindrome(string s) {
    
    int n = s.size();

    if (n < 2) {
        return s;
    }

    string res(1, s[0]);
    
    for (int i = 0; i < n; i++) {
        // odd palindrome check
        string odd_res = spreadPalindromeCheck(s, i - 1, i + 1);


        // even palindrome check
        string even_res = spreadPalindromeCheck(s, i, i + 1);

        if (odd_res.size() > res.size()) {
            res = odd_res;
        }

        if (even_res.size() > res.size()) {
            res = even_res;
        }
    }

    return res;
}


int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;

    return 0;
}