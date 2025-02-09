class Solution
{
public:
    void solve(vector<int> &nums, int i, int &ans, int step)
    {
        if (i == nums.size() - 1)
        {
            ans = min(ans, step);
            return;
        }
        if (i >= nums.size())
            return;
        // if(nums[i] == 0) return false; // stuck at that index

        for (int jump = 1; jump <= nums[i]; jump++)
            solve(nums, i + jump, ans, step + 1);
    }

    int jump(vector<int> &nums)
    {
        int ans = INT_MAX;
        solve(nums, 0, ans, 0);
        return ans;
    }
};