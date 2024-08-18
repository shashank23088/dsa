#include <bits/stdc++.h>

using namespace std;


int maxProduct(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) {
        return INT_MIN;
    }

    if (n == 1) {
        return nums[0];
    }

    int left = 0;
    int right = 0;
    int max_product = INT_MIN;
    int curr_product = 1;

    while (left <= right && right < n) {
        curr_product *= nums[right];
        max_product = max(curr_product, max_product);
        if (curr_product <= 0) {
            if (right == n - 1) {
                return max_product;
            }
            left = right + 1;
            right = right + 1;
            curr_product = 1;
        }
        right++;
    }

    return max_product;

}


int main() {
    vector<int> nums = {-2, 0, -1};
    cout << maxProduct(nums) << endl;

    return 0;
}