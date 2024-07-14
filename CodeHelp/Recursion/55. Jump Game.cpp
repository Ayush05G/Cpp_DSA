class Solution
{
public:
    bool solve(vector<int> &nums, int i)
    {
        if (i == nums.size() - 1)
            return true;
        if (i >= nums.size())
            return false;
        // if(nums[i] == 0) return false; // stuck at that index

        bool reAns = false;
        for (int jump = 1; jump <= nums[i]; jump++)
            reAns = reAns || solve(nums, i + jump);

        return reAns;
    }

    bool canJump(vector<int> &nums)
    {
        return solve(nums, 0);
    }
};