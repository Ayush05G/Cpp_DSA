class Solution {
public:
    map<pair<int, int>, vector<TreeNode*>> dp;

    vector<TreeNode*> allPossibleBSTs(int start, int end) {
        // Base cases
        if (start > end) return {nullptr};
        if (start == end) return {new TreeNode(start)};

        // Check if the result is already computed
        if (dp.find({start, end}) != dp.end()) {
            return dp[{start, end}];
        }

        vector<TreeNode*> ans;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = allPossibleBSTs(start, i - 1);
            vector<TreeNode*> right = allPossibleBSTs(i + 1, end);

            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }

        // Store the result in the dp map
        return dp[{start, end}] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return allPossibleBSTs(1, n);
    }
};