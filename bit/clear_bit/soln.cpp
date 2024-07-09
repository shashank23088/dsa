#include <bits/stdc++.h>

using namespace std;


int clearKthBitLS(int num, int k) {
    int mask = 1;
    return ( num & (~(mask << k)) );
}


int main() {
    int num = 13; 
    int k = 2;
    cout << clearKthBitLS(num, k) << endl;

    return 0;
}