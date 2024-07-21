// T(N) : O(N)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


// the sentence can have extra spaces or trailing spaces
// return sentence with single spaces b/w words
string reverseWords(string s) {

    string result = "";
    int n = s.size();
    int i = 0;

    while (i < n) {

        while (i < n && s[i] == ' ') {
            i++;
        }

        int j = i + 1;

        while (j < n && s[j] != ' ') {
            j++;
        }

        string word = s.substr(i, j - i);    // start idx, len
        if (result == "") {
            result += word;
        }

        else if (word != "") {
            result = word + " " + result;
        }

        i = j + 1;
    }

    return result;
}


int main() {
    string s = "   karan    halwa  nalla   ";
    cout << "[" << s << "]" << endl;
    string reverse_word = reverseWords(s);
    cout << "[" << reverse_word << "]" << endl;

    return 0;
}