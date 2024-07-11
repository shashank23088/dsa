// T(N) = O(N) [can be reduced]
// S(N) = [] (can't predict) just to return the answers, they're variables.

#include <bits/stdc++.h>

using namespace std;


vector<int> AllPrimeFactors(int n) {
    vector<int> all_primes;

    for (int i = 2; i <= n; i++) {    // for loop's max limit will keep changing, but worst case is n
        if (n % i == 0) {
            all_primes.emplace_back(i);
            while (n % i == 0) {
                n /= i;
            }
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