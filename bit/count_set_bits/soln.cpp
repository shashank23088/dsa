// stl already exists: __builtin_popcount(n)

#include <bits/stdc++.h>

using namespace std;


int countSetBits1(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num = num & (num - 1);
    }

    return count;

}

int countSetBits2(int num) {
    int count = 0;
    while (num >= 1) {
        count += (num & 1);    // increment if odd
        num = num >> 1;          // divison by 2
    }

    return count;

}


int main() {
    int num = 15; 
    cout << countSetBits1(num) << endl;
    cout << countSetBits2(num) << endl;

    return 0;
}