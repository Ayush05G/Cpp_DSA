class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int countmin = 1; 
        int countmax = 1;
        int longestmin = 1;
        int longestmax=1;
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                countmin++;
                longestmin = max(longestmin, countmin);
            } else {
                countmin = 1; 
            }
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                countmax++;
                longestmax = max(longestmax, countmax);
            } else {
                countmax = 1; 
            }
        }
        int longest=max(longestmin, longestmax);
        
        return longest;
    }
};