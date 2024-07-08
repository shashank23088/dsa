//Moore's Voting Algorithm
//The majority element will not cancel out

#include <bits/stdc++.h>

using namespace std;


int majorityElement(vector<int>& v) {
    int n = v.size();
    int count = 0;
    int element = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            element = v[i];
        }
        if (v[i] != element) {
            count--;
        }
        else {
            count++;
        }
    }

    int element_count = 0;
    for (auto itr : v) {
        if (itr == element) {
            element_count++;
        }
    }

    if (element_count > n/2) {
        return element;
    }

    return -1;
}


int main() {
    vector<int> v = {2,2,1,1,1,2,2};

    cout << majorityElement(v) << endl;

    return 0;
}