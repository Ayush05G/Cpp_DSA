#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            columnNumber--;
            result = char(columnNumber % 26 + 65) + result;
            columnNumber /= 26;
        }
        return result;
    }
};
