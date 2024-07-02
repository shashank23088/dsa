#include <bits/stdc++.h>
using namespace std;


vector<int> extractDigits(int num) {
    vector<int> extracted_digits;
    int curr_num = num;
    do{
        int extracted_digit = curr_num % 10;
        extracted_digits.emplace_back(extracted_digit);
        curr_num /= 10;
    } while(curr_num != 0);

    return extracted_digits;
}


int main() {
    int num;
    cout << "num: ";
    cin >> num;

    vector<int> extracted_digits = extractDigits(num);
    cout << "extracted digits: ";
    for (auto it : extracted_digits) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}