class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveTD(nums1, nums2, 0, -1, -1, dp, 0);
    }

private:
    int solveTD(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2, vector<vector<int>>& dp, int isSwap) {
        if (i == nums1.size()) return 0;

        if (dp[i][isSwap] != -1) return dp[i][isSwap];

        int swap = INT_MAX, noSwap = INT_MAX;

        // Check if swap is valid
        if (p1 < nums2[i] && p2 < nums1[i]) {
            swap = 1 + solveTD(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);
        }

        // Check if no swap is valid
        if (p1 < nums1[i] && p2 < nums2[i]) {
            noSwap = solveTD(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);
        }

        return dp[i][isSwap] = min(swap, noSwap);
    }
};