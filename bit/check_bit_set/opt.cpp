// using right or left shift operator

#include <bits/stdc++.h>

using namespace std;

// T(N) = O(1)
bool checkKthBitLS(int num, int k) {
    int mask = 1;
    if ( (num & (mask << k)) == 0 ) {
        return false;
    }
    return true;
}


bool checkKthBitRS(int num, int k) {
    int mask = 1;
    if ( ((num >> k) & mask) == 1) {
        return true;
    }
    return false;
}


int main() {
    int num = 20;
    int k = 0;
    cout << checkKthBitLS(num, k) << endl;
    cout << checkKthBitRS(num, k) << endl;

    return 0;
}