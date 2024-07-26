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
    string s = "1";

    for (int j = 2; j <= n; j++) {
        string rle_val = rle(s);
        s = rle_val;
    }

    return s;

}


int main() {
    cout << countAndSay(4) << endl;

    return 0;
}
