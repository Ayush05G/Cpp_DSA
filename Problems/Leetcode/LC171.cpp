#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
      int result = 0;
      int length = columnTitle.length();
    
        for (int i = 0; i < length; ++i) {
            char ch = columnTitle[i];
            int value = ch - 'A' + 1;
            result = result * 26 + value;
        }
    return result;
    }
};