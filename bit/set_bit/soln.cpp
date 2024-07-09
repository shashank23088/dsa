#include <bits/stdc++.h>

using namespace std;


int setKthBitLS(int num, int k) {
    int mask = 1;
    return ( num | (mask << k) );
}


int main() {
    int num = 9; 
    int k = 2;
    cout << setKthBitLS(num, k) << endl;

    return 0;
}