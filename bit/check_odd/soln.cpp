#include <bits/stdc++.h>

using namespace std;


int checkOdd(int& num) {
    return ((num & 1) != 0);
}


int main() {
    int num = 16; 
    cout << checkOdd(num) << endl;

    return 0;
}