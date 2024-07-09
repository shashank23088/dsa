// T(start, goal) = O(log2(start ^ goal))   
// S(start, goal) = O(1)

#include <bits/stdc++.h>

using namespace std;


int minBitFlips(int start, int goal) {

    int n_bits_to_flip = 0;
    int temp = (start ^ goal);
    while (temp != 0) {
        n_bits_to_flip++;
        temp = (temp) & (temp - 1);
    }
    return n_bits_to_flip;

}


int main () {
    int start = 10;
    int goal = 7;
    cout << minBitFlips(10, 7) << endl;

    return 0;
}