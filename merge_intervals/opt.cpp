// in brute force, just check curr_pair against every nxt_pair in the orig array everytime -> O(2N)
// T(N) = O(NlogN) + O(N)
// S(N) = O(N)

#include <bits/stdc++.h>

using namespace std;


vector< vector<int> > mergeIntervals(vector< vector<int> >& intervals) {

    int n = intervals.size();
    vector< vector<int> > merged_intervals;
    sort(intervals.begin(), intervals.end());
    merged_intervals.emplace_back(intervals[0]);
    int j = 0;
    vector<int> curr_pair = merged_intervals[j];

    for (int i = 1; i <= n - 1; i++) {
        vector<int> nxt_pair = intervals[i];
        if (curr_pair[1] >= nxt_pair[1]) {
            continue;
        }
        if (curr_pair[1] >= nxt_pair[0]) {
            merged_intervals[j][1] = nxt_pair[1];
            curr_pair = merged_intervals[j];
        }
        else {
            merged_intervals.emplace_back(nxt_pair);
            curr_pair = nxt_pair;
            j += 1;
        }
    }
    
    return merged_intervals;

}


int main() {
    vector< vector<int> > intervals = {{1,3},{2,6},{8,10},{15,18}};
    intervals = mergeIntervals(intervals);

    for (auto itr : intervals) {
            cout << "{" << itr[0] << ", " << itr[1] << "} ";
    }
    cout << endl;

    return 0;
}