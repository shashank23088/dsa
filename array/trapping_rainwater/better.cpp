// T(N) : O(2N)
// S(N) : O(2N)

#include <bits/stdc++.h>

using namespace std;


// return units of rain water trapped
int trap(vector<int>& height) {
    
    int trapped_water = 0;
    int n = height.size();
    int curr_left_max = 0; 
    int curr_right_max = 0;
    vector<int> max_left(n, 0);
    vector<int> max_right(n, 0);

    for (int i = 0; i < n ; i++) {

        curr_left_max = max(curr_left_max, height[i]);
        curr_right_max = max(curr_right_max, height[n - 1 - i]);

        max_left[i] = curr_left_max;
        max_right[n - 1 - i] = curr_right_max;

    }

    for (int i = 0; i < n; i++) {

        trapped_water += max(min(max_left[i], max_right[i]) - height[i], 0);
    }

    return trapped_water;
}


int main() {
    // given elevation heights
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;

    return 0;
}