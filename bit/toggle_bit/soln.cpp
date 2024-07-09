#include <bits/stdc++.h>

using namespace std;


int toggleKthBitLS(int num, int k) {
    int mask = 1;
    return ( num ^ (mask << k) );
}


int main() {
    int num = 13; 
    int k = 1;
    cout << toggleKthBitLS(num, k) << endl;

    return 0;
}