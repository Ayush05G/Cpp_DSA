class Solution
{
public:
    void solve(vector<string> &ans, string &out, int open, int close, int n)
    {
        if (open + close == 2 * n)
        {
            ans.push_back(out);
            return;
        }

        if (open < n)
        {
            out.push_back('(');
            solve(ans, out, open + 1, close, n);
            out.pop_back(); // backtracking
        }

        if (close < open)
        {
            out.push_back(')');
            solve(ans, out, open, close + 1, n);
            out.pop_back(); // backtracking
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string out;
        solve(ans, out, 0, 0, n);
        return ans;
    }
};