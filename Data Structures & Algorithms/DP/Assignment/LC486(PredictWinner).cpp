class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];

        int diffByStart = nums[start] - solve(nums, start + 1, end);
        int diffByEnd = nums[end] - solve(nums, start, end - 1);
        return max(diffByStart, diffByEnd);
    }

    int solveTD(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start == end) return nums[start];

        if (dp[start][end] != -1) return dp[start][end];

        int diffByStart = nums[start] - solveTD(nums, start + 1, end, dp);
        int diffByEnd = nums[end] - solveTD(nums, start, end - 1, dp);
        dp[start][end] = max(diffByStart, diffByEnd);
        return dp[start][end];
    }

    bool predictTheWinner(vector<int>& nums) {
        // return solve(nums, 0, nums.size() - 1) >= 0;

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solveTD(nums, 0, nums.size() - 1, dp) >= 0;
    }
};
