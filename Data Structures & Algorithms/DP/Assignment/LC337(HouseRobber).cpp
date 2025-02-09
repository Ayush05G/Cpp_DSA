class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root) return 0;

        if(dp.find(root) != dp.end()) return dp[root];

        int robThisHouse = 0, dontRobThisHouse = 0;

        // rob current house
        robThisHouse += root->val;
        if(root->left)
            robThisHouse += solve(root->left->left, dp) + solve(root->left->right, dp);
        if(root->right)
            robThisHouse += solve(root->right->left, dp) + solve(root->right->right, dp);

        // don't rob current house
        dontRobThisHouse = solve(root->left, dp) + solve(root->right, dp);

        // return max rob this house, don't rob this house
        dp[root] = max(robThisHouse, dontRobThisHouse);
        return dp[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};
//TC & SC 0(n)
