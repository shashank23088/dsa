#include <bits/stdc++.h>

using namespace std;


string decimalToBinary (int& num) {
    string binary_num = "";
    while (num != 0) {
        if (num % 2 == 1) {
            binary_num += "1";
        }
        else {
            binary_num += "0";
        }
        num /= 2;
    }
    reverse(binary_num.begin(), binary_num.end());
    return binary_num;
}


bool checkKthBit(int num, int k) {
    string binary_num = decimalToBinary(num);
    int req_bit_idx = binary_num.size() - 1 - k;
    if (req_bit_idx < 0 || binary_num[req_bit_idx] == '0') {
        return false;
    }
    return true;
}


int main() {
    int num = 13;
    int k = 2;
    cout << checkKthBit(num, k) << endl;

    return 0;
}