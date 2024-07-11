// T(N) = O(N^1/2 * 2 *N^1/2)    [apprx.]
// S(N) = [] (can't predict) just to return the answers, they're variables.

#include <bits/stdc++.h>

using namespace std;


bool isPrime(int n) {    // O(N^1/2)
    int count = 0;
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


// O(N*N^1/2)
// better approach available
// vector<int> AllPrimeFactors(int n) {
//     vector<int> all_primes;

//     for (int i = 2; i <= n; i++) {
//         if ((n % i == 0) && isPrime(i)) {
//             all_primes.emplace_back(i);
//         }
//     }
//     return all_primes;
// }


// adding both i and n/i together
// O(N^1/2 * 2 * N^1/2)
vector<int> AllPrimeFactors(int n) {
    vector<int> all_primes;

    for (int i = 2; i <= sqrt(n); i++) {
        if ((n % i == 0) && isPrime(i)) {
            all_primes.emplace_back(i);
        }
        if (n % i == 0 && (n / i != i)) {
            all_primes.emplace_back(n / i);
        }
    }
    return all_primes;
}


int main() {
    int n = 98;
    vector<int> all_primes = AllPrimeFactors(n);

    for (auto itr : all_primes) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}