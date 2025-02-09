#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if b is a subset of a
    unordered_map<int, int> map;

    bool isSubset(vector<int> &a, vector<int> &b) {
        vector<int>a1=a;
        vector<int>a2=b;
        int m=a2.size();
        int n=a1.size();
        // Map hashing using a1
    for (int i = 0; i < n; i++) {
        map[a1[i]]++;
    }

    // Check whether all elements of a2 are present in a1
    for (int i = 0; i < m; i++) {
        if (map.find(a2[i]) == map.end()) {
            return false;
            break;
        } else {
            // Element is present
            if (map[a2[i]] > 0) {
                map[a2[i]]--;
            } else {
                return false;
                break;
            }
        }
    }
    return true;
}
};