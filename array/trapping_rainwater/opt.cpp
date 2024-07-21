// T(N) : O(N)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


// return units of rain water trapped
int trap(vector<int>& height) {
    
    int trapped_water = 0;
    int n = height.size();
    int curr_left_max = 0; 
    int curr_right_max = 0;
    int left = 0;
    int right = n - 1;

    while (left <= right) {

        if (height[left] <= height[right]) {    // ensures on the right, there is some building 
                                                // with min height height[left], so that rainwater
                                                // can be trapped.

            if (height[left] >= curr_left_max) {    // max height, so can't trap water
                curr_left_max = height[left];
            }

            else {
                trapped_water += curr_left_max - height[left];
            }

            left++;
        }

        else {                                  // ensures on the left, there is some building 
                                                // with min height height[right], so that rainwater
                                                // can be trapped.

            if (height[right] >= curr_right_max) {    // max height, so can't trap water
                curr_right_max = height[right];
            }

            else {
                trapped_water += curr_right_max - height[right];
            }

            right--;
        }

    }

    return trapped_water;
}


int main() {
    // given elevation heights
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;

    return 0;
}