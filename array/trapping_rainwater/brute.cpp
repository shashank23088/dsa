// T(N) : O(N^2)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


// return units of rain water trapped
int trap(vector<int>& height) {
    
    int trapped_water = 0;
    int n = height.size();

    for (int i = 1; i < n - 1; i++) {

        int max_rt = INT_MIN;
        for (int j = i + 1; j < n; j++) {
            max_rt = max(max_rt, height[j]);
        }

        int max_left = INT_MIN;
        for (int j = 0; j <= i; j++) {
            max_left = max(max_left, height[j]);
        }

        trapped_water += max(min(max_left, max_rt) - height[i], 0);
    }

    return trapped_water;
}


int main() {
    // given elevation heights
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;

    return 0;
}