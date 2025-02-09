class Solution
{
public:
    bool solve(vector<int> &nums, int target, int i)
    {
        if (target < 0 || i == nums.size())
            return false;
        if (target == 0)
            return true;

        bool inc = solve(nums, target - nums[i], i + 1);
        bool exc = solve(nums, target, i + 1);

        return inc || exc;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum % 2) != 0)
            return false; // odd sum

        int target = sum >> 1;
        return solve(nums, target, 0);
    }
};