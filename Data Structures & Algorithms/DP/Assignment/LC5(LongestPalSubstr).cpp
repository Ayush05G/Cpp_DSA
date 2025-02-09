class Solution {
public:
    int maxlen = 1, start = 0;

    bool solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) {
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool flag = false;
        if (s[i] == s[j]) {
            flag = solve(s, i + 1, j - 1, dp);
        }
        if (flag) {
            int currlen = j - i + 1;
            if (currlen > maxlen) {
                maxlen = currlen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                solve(s, i, j, dp);
            }
        }
        return s.substr(start, maxlen);
    }
};
