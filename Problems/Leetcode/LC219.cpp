#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> valueToIndexMap;

        for (int i = 0; i < nums.size(); ++i) {
            
            if (valueToIndexMap.count(nums[i])) {
                
                if (i - valueToIndexMap[nums[i]] <= k) {
                    return true;
                }
            }
            valueToIndexMap[nums[i]] = i;
        }
        return false;
    }
};
