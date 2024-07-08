//using hashmap

#include <bits/stdc++.h>

using namespace std;


int majorityElement(vector<int>& v) {
    int n = v.size();
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        // int key = v[i];
        // if (m.find(key) != m.end()) {
        //     m[key] += 1;
        // }
        // else {
        //     m[v[i]] = 1;
        // } 
        m[v[i]]++;
    }

    for (auto itr : m) {
        if (itr.second > n/2) {
            return itr.first;
        }
    }

    return -1;
}


int main() {
    vector<int> v = {2,2,1,1,1,2,2};

    cout << majorityElement(v) << endl;

    return 0;
}