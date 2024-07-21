#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    
    

}


int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector< vector<int> > triplets = threeSum(nums);

    for (auto itr : triplets) {
        for (auto it : itr) {
            cout << it << " ";
        }
        cout << endl;
    } 

    return 0;
}