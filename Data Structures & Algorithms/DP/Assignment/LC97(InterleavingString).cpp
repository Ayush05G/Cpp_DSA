class Solution {
public:
bool solve(string &s1, string &s2, string &s3, int i, int j, int k) {
    if (i == s1.size() && j == s2.size() && k == s3.size()) 
        return true;

    bool flag = false;

    if (i < s1.size() && s1[i] == s3[k])
        flag = flag || solve(s1, s2, s3, i + 1, j, k + 1);

    if (j < s2.size() && s2[j] == s3[k])
        flag = flag || solve(s1, s2, s3, i, j + 1, k + 1);

    return flag;
}

bool solveTD(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp) {
    if (i == s1.size() && j == s2.size() && k == s3.size()) 
        return true;

    if (dp[i][j][k] != -1) 
        return dp[i][j][k];

    bool flag = false;

    if (i < s1.size() && s1[i] == s3[k])
        flag = flag || solveTD(s1, s2, s3, i + 1, j, k + 1, dp);

    if (j < s2.size() && s2[j] == s3[k])
        flag = flag || solveTD(s1, s2, s3, i, j + 1, k + 1, dp);

    return dp[i][j][k] = flag;
}

bool solveBU(string &s1, string &s2, string &s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

    // If the total lengths don't match, return false
    if (n1 + n2 != n3) return false;

    // Create a 3D DP table where dp[i][j][k] represents whether s3[0...k-1] 
    // can be formed by interleaving s1[0...i-1] and s2[0...j-1]
    vector<vector<vector<bool>>> dp(n1 + 1, vector<vector<bool>>(n2 + 1, vector<bool>(n3 + 1, false)));

    // Base case: when all strings are empty
    dp[0][0][0] = true;

    // Fill the DP table
    for (int k = 0; k <= n3; ++k) {
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                if (i + j == k) { // Only process valid states where i + j == k
                    // If the current character of s3 matches s1
                    if (i > 0 && s1[i - 1] == s3[k - 1]) {
                        dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - 1];
                    }
                    // If the current character of s3 matches s2
                    if (j > 0 && s2[j - 1] == s3[k - 1]) {
                        dp[i][j][k] = dp[i][j][k] || dp[i][j - 1][k - 1];
                    }
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
        return false;

    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
    return solveBU(s1, s2, s3);
}
};