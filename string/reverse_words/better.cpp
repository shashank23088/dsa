// T(N) : O(N) + O(#words)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


void reverseWord(string& word) {

    int n = word.size();
    int low = 0;
    int high = n - 1;

    while (low < high) {
        swap(word[low], word[high]);
        low++;
        high--;
    }

}


// the sentence can have extra spaces or trailing spaces
// return sentence with single spaces b/w words
string reverseWords(string s) {

    if (s.empty()) {
        return s;
    }

    if (s.size() == 1) {
        return s;
    }

    int n = s.size();
    
    int j = 0;
    while (j < n && s[j] == ' ') {
        j++;
    }

    int i = n - 1;
    string temp = "";
    string result = "";

    while (i >= j) {

        if (s[i] == ' ' && temp != "") {
            reverseWord(temp);
            result += temp + ' ';
            temp = "";
        }

        else if (s[i] != ' ') {
            temp += s[i];
        }

        i--;

    }

    reverseWord(temp);
    result += temp;

    return result;

}


int main() {
    string s = "  hello world  ";
    cout << "[" << s << "]" << endl;
    string reverse_word = reverseWords(s);
    cout << "[" << reverse_word << "]" << endl;

    return 0;
}