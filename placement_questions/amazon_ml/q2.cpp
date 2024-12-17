#include <bits/stdc++.h>

using namespace std;


int groupStudents(vector<int>& levels, int maxSpread) {

    if (levels.size() == 0) {
        return 0;
    }

    sort(levels.begin(), levels.end());

    int group_count = 1;
    int left = levels[0];
    for(int right = 0; right < levels.size(); right++) {
        if(levels[right] - left > maxSpread) {
            group_count++;
            left = levels[right];
        }
    }

    return group_count;
}


int main() {
    vector<int> levels = {1, 4, 7, 3, 4};
    int max_spread = 2;
    cout << groupStudents(levels, max_spread) << endl;

    return 0;
}