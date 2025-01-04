class Solution {
public:
    int solve(vector<int>& nums, int target, int i) {
        if (i == nums.size()) return target == 0 ? 1 : 0;

        int plus = solve(nums, target - nums[i], i + 1);
        int minus = solve(nums, target + nums[i], i + 1);

        return plus + minus;
    }

    int solveTD(vector<int>& nums, int target, int i, map<pair<int, int>, int>& dp) {
        if (i == nums.size()) return target == 0 ? 1 : 0;

        if (dp.find({i, target}) != dp.end()) return dp[{i, target}];

        int plus = solveTD(nums, target - nums[i], i + 1, dp);
        int minus = solveTD(nums, target + nums[i], i + 1, dp);

        return dp[{i, target}] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // return solve(nums, target, 0);
        map<pair<int, int>, int> dp; // {i, target} -> no. of ways
        return solveTD(nums, target, 0, dp);
    }
};
