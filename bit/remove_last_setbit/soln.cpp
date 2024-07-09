#include <bits/stdc++.h>

using namespace std;


int removeLastSetBit(int num) {
    return num & (num - 1);

}


int main() {
    int num = 40; 
    cout << removeLastSetBit(num) << endl;

    return 0;
}