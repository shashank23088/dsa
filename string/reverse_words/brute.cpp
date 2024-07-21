// T(N) : O(N) + O(#words)
// S(N) : O(#words)

#include <bits/stdc++.h>

using namespace std;


// the sentence can have extra spaces or trailing spaces
// return sentence with single spaces b/w words
string reverseWords(string s) {

    if (s.empty()) {
        return s;
    }

    if (s.size() == 1) {
        return s;
    }
    
    int i = 0;
    int n = s.size();
    stack<string> st;

    while (i < n) {    // O(N)

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i >= n) {
            break;
        }

        string temp = "";
        while (i < n && s[i] != ' ') {
            temp += s[i];
            i++;
        }
        st.emplace(temp);

    }

    string result = "";
    int stack_size = st.size();

    for (int i = 0; i < stack_size - 1; i++) {
        result += st.top() + ' ';
        st.pop();
    }
    result += st.top();
    st.pop();

    return result;

}


int main() {
    string s = "  hello world  ";
    string reverse_word = reverseWords(s);
    cout << "[" << reverse_word << "]" << endl;

    return 0;
}