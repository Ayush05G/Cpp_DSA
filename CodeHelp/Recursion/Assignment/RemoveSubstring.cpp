#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string full, string pattern) {
        
        while(full.find(pattern) != string::npos) {
            full.erase(full.find(pattern), pattern.length());
        }
        return full;

    }
};