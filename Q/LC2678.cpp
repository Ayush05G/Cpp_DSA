#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;
        for (int i=0;i<details.size();i++) {
            int age = stoi(details[i].substr(11, 2));
            seniorCount += (age > 60) ? 1 : 0;
        }
        return seniorCount;
    }
};