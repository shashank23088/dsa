#include <bits/stdc++.h>

using namespace std;


pair<pair<int, int>, int> maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int minimal = prices[0];
    int s, e = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++) {
        int profit = prices[i] - minimal;
        if (profit > max_profit) {
            max_profit = profit;
            e = i;
        }
        // max_profit = max(max_profit, profit);
        // minimal = min(minimal, prices[i]);
        if (prices[i] < minimal) {
            minimal = prices[i];
            s = i;
        }
    }

    return make_pair(make_pair(s, e), max_profit);
}


int main() {
    vector<int> prices = {7,1,5,3,6,4};

    pair<pair<int, int>, int> p = maxProfit(prices);
    cout << p.second << endl;
    cout << p.first.first << " " << p.first.second << endl;

    return 0;
}
