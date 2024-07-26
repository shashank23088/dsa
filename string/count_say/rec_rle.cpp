#include <bits/stdc++.h>

using namespace std;


string rle(string s) {

    int n = s.size();
    if (n == 1) {
        return "1" + s;
    }

    string res = "";
    int curr_freq = 1;
    s += "#";
    n++;

    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] == s[i]) {
            curr_freq++;
        }

        else {
            res += to_string(curr_freq) + s[i];
            curr_freq = 1;
        }

    }

    return res;
}


string countAndSay(int n) {
    
    if (n == 1) {
        return "1";
    }

    return rle( countAndSay(n - 1) );

}


int main() {
    cout << countAndSay(10) << endl;

    return 0;
}
