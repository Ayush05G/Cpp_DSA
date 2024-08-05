#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoSum;
        int n = nums.size();

        
        for(int i = 0; i<n-1;i++)
        {
            for(int j = i+1; j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    twoSum.push_back(i);
                    twoSum.push_back(j);
                    
                }
            }
        }
        return twoSum;
    }
};