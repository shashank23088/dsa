// T(N) : O(NlogN) + O(N)
// S(N) : O(N)

#include <bits/stdc++.h>

using namespace std;


// return #unique elements in nums
// outplace
int removeDuplicates(vector<int>& nums) {

    // unique -> set
    set<int> nums_unique;
    for (auto itr : nums) {    // NlogN
        nums_unique.insert(itr);    // log(N)
    }    

    int count = 0;
    nums.clear();
    for (auto itr : nums_unique) {    // N
        count++;
        nums.emplace_back(itr);
    }

    return count;

}


int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums) << endl;

    return 0;
}