#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
       int n=nums.size();
       if (n <= 4) return 0;
       sort(nums.begin(), nums.end());
       int min_diff = INT_MAX;
        min_diff = min(min_diff, nums[n-1] - nums[3]); // Changing 3 smallest elements
        min_diff = min(min_diff, nums[n-2] - nums[2]); // Changing 2 smallest and 1 largest
        min_diff = min(min_diff, nums[n-3] - nums[1]); // Changing 1 smallest and 2 largest
        min_diff = min(min_diff, nums[n-4] - nums[0]); // Changing 3 largest elements
        
        return min_diff;
        
    }
};