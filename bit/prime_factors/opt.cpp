// T(N) = O(N^1/2 * logN)
// S(N) = [] (can't predict) just to return the answers, they're variables.

#include <bits/stdc++.h>

using namespace std;


vector<int> AllPrimeFactors(int n) {
    vector<int> all_primes;

    for (int i = 2; i <= sqrt(n); i++) {   // N^1/2 
        if (n % i == 0) {
            all_primes.emplace_back(i);
            while (n % i == 0) {    // logN
                n /= i;
            }
        }
    }

    if (n != 1) {    // for cases where N itself is prime
        all_primes.emplace_back(n);
    }

    return all_primes;
}


int main() {
    int n = 37;
    vector<int> all_primes = AllPrimeFactors(n);

    for (auto itr : all_primes) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}