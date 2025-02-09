#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string solve(string& s1, string& s2, int carry, int i, int j) {
        if (i < 0 && j < 0) {
        if (carry)
        return string(1, carry + '0');
        return "";
    }
    int x = i<0? 0:s1[i] - '0', y = j < 0? 0: s2[j] - '0', sum;
    sum = x + y + carry;
    return solve(s1, s2, sum / 10, i-1, j- 1) + (char) ((sum % 10) + '0');
}

    string addStrings(string num1, string num2) {
    return solve(num1, num2, 0, num1.length() - 1, num2.length() - 1);
    }
};