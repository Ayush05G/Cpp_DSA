#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//First approach(String to Integer)
class Solution {
 public:
  int romanToInt(string s) {
    int ans = 0;
    vector<int> roman(128);

    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    for (int i = 0; i + 1 < s.length(); ++i)
      if (roman[s[i]] < roman[s[i + 1]])
        ans -= roman[s[i]];
      else
        ans += roman[s[i]];

    return ans + roman[s.back()];
  }
};

//Second approach(Unordered Map)
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int i = s.length() - 1;
    int result = value[s[i--]];
    while (i >= 0) {
        if (value[s[i]] < value[s[i+1]]) {
            result -= value[s[i--]]; 
        } else {
            result += value[s[i--]];
        }
    }
    return result;
}
};