#include <bits/stdc++.h>

using namespace std;


int checkPowerOfTwo(int num) {
    return ( ( num & (num - 1) ) == 0 );

}


int main() {
    int num = 32; 
    cout << checkPowerOfTwo(num) << endl;

    return 0;
}