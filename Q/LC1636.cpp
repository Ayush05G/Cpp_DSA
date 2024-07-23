#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // 201 in size to account for numbers from -100 to 100 (inclusive)
        vector<int> frequency(201, 0);
        // Counting each number's frequency
        // Shift the index to fit in the range of [0, 200]
        for (int num : nums) {
            ++frequency[num+100];
        }
        // Custom sort
        sort(nums.begin(), nums.end(), [&](const int num1, const int num2) {
            // When frequencies equal, sort by number value in descending order
            if (frequency[num1+100] == frequency[num2+100]) return num1 > num2;
            // Otherwise in ascending order
            return frequency[num1+100] < frequency[num2+100];
        });
        return nums;
    }
};