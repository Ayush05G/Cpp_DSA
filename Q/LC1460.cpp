#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method to determine if two vectors can be made equal by reordering
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Sort the target vector in non-decreasing order
        sort(target.begin(), target.end());
      
        // Sort the arr vector in non-decreasing order
        sort(arr.begin(), arr.end());
      
        // Compare the sorted vectors to check if they are equal
        return target == arr;
    }
};
