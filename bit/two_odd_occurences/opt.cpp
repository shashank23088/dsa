// T(N) = O(N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    int bucket1 = 0;    // set bit
    int bucket2 = 0;    // unset bit
    vector<long long int> two_odd_num;

    // xor each element so only xor remaining will be num1 ^ num2
    // O(N)
    int xor_all = Arr[0];
    for (int i = 1; i < N; i++) {
        xor_all ^= Arr[i];
    }

    // checking the first set bit index, (index value where bit is change for num1 and num2)
    int first_set_bit_number = xor_all ^ (xor_all & (xor_all - 1));

    // NOT NECESSARY, HENCE OMMITTED
    // int set_bit_idx = 0;

    // // O(1), as max can be O(32)
    // while (first_set_bit_number % 2 != 1) {
    //     first_set_bit_number /= 2;
    //     set_bit_idx++;
    // }   

    // placement of number into 2 buckets according to the set bit idx being set or not
    // num1 and num2 will be in diffferent buckets always
    // xoring both buckets will cancel out all numbers except num1 and num2
    // O(N)
    for (int i = 0; i < N; i++) {
        if (Arr[i] & first_set_bit_number) {    // will be zero if first right bit is not set
            bucket1 ^= Arr[i];
        }
        else {
            bucket2 ^= Arr[i];
        }
    }

    two_odd_num.insert(two_odd_num.end(), {bucket1, bucket2});

    // reverse sort the list according to the problem
    sort(two_odd_num.rbegin(), two_odd_num.rend());    // O(1)    [as only two elements to be sorted]
    return two_odd_num;

}


int main() {
    int N = 8;
    long long int Arr[N] = {4, 2, 4, 5, 2, 3, 3, 1};
    vector<long long int> two_odd_num = twoOddNum(Arr, N);

    for (auto itr : two_odd_num) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}