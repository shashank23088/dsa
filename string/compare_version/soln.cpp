#include <bits/stdc++.h>

using namespace std;


int extractNumFromVersion(string version, int& curr_idx) {
    int num = 0;
    int n = version.size();

    // trimming leading zeroes
    while (curr_idx < n && version[curr_idx] == '0') {
        curr_idx++;
    }

    while (curr_idx < n && version[curr_idx] != '.') {
        num = num*10 + (version[curr_idx] - 48);
        curr_idx++;
    }

    return num;
}


int compareVersion(string version1, string version2) {
    
    int i = 0, j = 0;
    int nv1 = version1.size(), nv2 = version2.size();

    while(i < nv1 && j < nv2) {

        int num_v1 = extractNumFromVersion(version1, i);
        int num_v2 = extractNumFromVersion(version2, j);
        
        if (num_v1 > num_v2) {
            return 1;
        }

        if (num_v1 < num_v2) {
            return -1;
        }

        i++;
        j++;
    }

    while (i < nv1) {
        int num1 = extractNumFromVersion(version1, i);
        if (num1 != 0) {
            return 1;
        }
        i++;
    }

    while (j < nv2) {
        int num2 = extractNumFromVersion(version2, j);
        if (num2 != 0) {
            return -1;
        }
        j++;
    }

    return 0;

}


int main() {
    string version1 = "1.0";
    string version2 = "1.0.0.0";

    cout << compareVersion(version1, version2) << endl;

    return 0;
}