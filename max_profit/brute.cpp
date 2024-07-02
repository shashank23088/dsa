#include <bits/stdc++.h>

using namespace std;


pair<pair<int, int>, int> maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int max_s, max_e = -1;
    int n = prices.size();

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int profit = prices[j] - prices[i];
            if (profit > max_profit) {
                max_s = i;
                max_e = j;
                max_profit = profit;
            }
        }
    }

    return make_pair(make_pair(max_s, max_e), max_profit);
}


int main() {
    vector<int> prices = {7,1,5,3,6,4};

    pair<pair<int, int>, int> p = maxProfit(prices);
    cout << p.second << endl;
    cout << p.first.first << " " << p.first.second << endl;

    return 0;
}
