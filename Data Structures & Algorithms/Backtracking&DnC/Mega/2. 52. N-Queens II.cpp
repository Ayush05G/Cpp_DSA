class Solution
{
public:
    bool isSafe(vector<string> &B, int row, int col)
    {
        // row check to the left
        for (int i = col - 1; i >= 0; --i)
        {
            if (B[row][i] == 'Q')
                return 0;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; j--, i--)
        {
            if (B[i][j] == 'Q')
                return 0;
        }

        for (int i = row, j = col; i < B.size() && j >= 0; j--, i++)
        {
            if (B[i][j] == 'Q')
                return 0;
        }
        return 1;
    }
    bool find(vector<string> &B, int col, vector<vector<string>> &ans)
    {
        int n = B.size();
        if (col >= n)
        {
            ans.push_back(B);
            return true;
        }
        int res = 0;
        for (int row = 0; row < n; row++)
        {
            if (isSafe(B, row, col))
            {
                B[row][col] = 'Q';
                res |= find(B, col + 1, ans);
                B[row][col] = '.';
            }
        }
        return res;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> B;
        for (int i = 0; i < n; ++i)
        {
            string s = "";
            for (int j = 0; j < n; ++j)
            {
                s.push_back('.');
            }
            B.push_back(s);
        }
        vector<vector<string>> ans;
        find(B, 0, ans);
        return ans;
    }

    int totalNQueens(int n)
    {
        auto ans = solveNQueens(n);
        return ans.size();
    }
};