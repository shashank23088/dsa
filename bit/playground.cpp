#include <bits/stdc++.h>

using namespace std;


// T(N) = O(log2N) [log base2 N]
// S(N) = O(log2N)
string decimalToBinary(int& num) {
    string binary_num = "";
    while (num != 0) {
        binary_num += to_string(num % 2);
        num /= 2;
    }
    reverse(binary_num.begin(), binary_num.end());
    return binary_num;
}

// T(N) = O(N)
// S(N) = O(1)
int binaryToDecimal(string& binary_num) {
    int num = 0;
    int n = binary_num.size();
    int pow_2 = 1;

    for (int i = 0; i < n; i++) {
        char binary_char = binary_num[n - i - 1];
        if (binary_char == '1') {
            num += pow_2; 
        }
        pow_2 *= 2;
    }

    return num;
}


int main() {
    int num = 13;
    string binary_num = "1101";
    cout << decimalToBinary(num) << endl;
    cout << binaryToDecimal(binary_num) << endl;

    return 0;
}