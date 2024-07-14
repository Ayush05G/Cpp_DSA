// class Solution {
// public:
//     int solve(vector<vector<int>>& mat, int&target, int sum, int row){
//         if(row == mat.size())
//             return abs(target - sum);

//         int ans = INT_MAX;
//         for(int col = 0;col<mat[row].size();col++){
//             int reAns = solve(mat, target, sum + mat[row][col], row + 1);
//             ans = min(ans, reAns);
//         }
//         return ans;
//     }

//     int minimizeTheDifference(vector<vector<int>>& mat, int target) {
//         int sum = 0, row = 0;
//         return solve(mat, target, sum, row);
//     }
// };

class Solution
{
public:
    void solve(vector<vector<int>> &mat, int &target, int sum, int row, int &mini)
    {
        if (row == mat.size())
        {
            mini = min(mini, abs(target - sum));
            return;
        }

        for (int col = 0; col < mat[row].size(); col++)
        {
            solve(mat, target, sum + mat[row][col], row + 1, mini);
        }
    }

    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        int sum = 0, row = 0, mini = INT_MAX;
        solve(mat, target, sum, row, mini);
        return mini;
    }
};