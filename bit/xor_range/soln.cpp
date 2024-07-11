// brute using for loop (O(N))
// has to be done in O(1)
// T(N) = O(1) = S(N)

#include <bits/stdc++.h>

using namespace std;


// int findXOR(int l, int r) {
//     int xor_value = l;
//     for (int i = l + 1; i <= r; i++) {
//         xor_value ^= i;
//     }
//     return xor_value;
// }


// XOR from 1 -> n
int XOR_1n(int n) {
    int rem = n % 4;
    if (rem == 1) {
        return 1;
    }
    if (rem == 2) {
       return n + 1; 
    }
    if (rem == 3) {
        return 0;
    }
    return n;
}


// XOR from l -> r
int findXOR(int l, int r) {
    return XOR_1n(l - 1) ^ XOR_1n(r);
}


int main() {
    int l = 4; 
    int r = 8;
    cout << findXOR(l, r) << endl;

    return 0;
}