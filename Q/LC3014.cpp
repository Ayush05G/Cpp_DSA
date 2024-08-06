#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequency(26, 0);
        for (char& c : word) {
            ++frequency[c - 'a'];
        }
        sort(frequency.rbegin(), frequency.rend());
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            totalPushes += (i / 8 + 1) * frequency[i];
        }
        return totalPushes;
    }
};