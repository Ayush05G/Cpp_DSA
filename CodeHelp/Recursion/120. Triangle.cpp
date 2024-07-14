class Solution
{
public:
    // int solve(vector<vector<int>>& triangle, int row, int col) {
    //     if(row == triangle.size() - 1){
    //         return triangle[row][col];
    //     }
    //     int down = triangle[row][col] + solve(triangle, row + 1, col);
    //     int plus = triangle[row][col] + solve(triangle, row + 1, col + 1);
    //     return min(down, plus);
    // }

    // void solve(vector<vector<int>>& triangle, int row, int col, int sum, int &ans) {
    //     if(row == triangle.size()){
    //         ans = min(ans, sum);
    //         return;
    //     }

    //     solve(triangle, row + 1, col, sum + triangle[row][col], ans);
    //     solve(triangle, row + 1, col + 1, sum + triangle[row][col], ans);
    // }

    int solve(vector<vector<int>> &triangle, int row, int col)
    {
        if (row == triangle.size())
        {
            return 0;
        }
        int down = triangle[row][col] + solve(triangle, row + 1, col);
        int plus = triangle[row][col] + solve(triangle, row + 1, col + 1);
        return min(down, plus);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        return solve(triangle, 0, 0);

        // int ans = INT_MAX;
        // solve(triangle, 0, 0, 0, ans);
        // return ans;
    }
};