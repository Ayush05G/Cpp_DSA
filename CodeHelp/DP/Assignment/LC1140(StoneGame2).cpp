class Solution {
public:
// int solveTD(vector<int>& piles, int i, int M, int alice, vector<vector<vector<int>>>& dp){
//     if(i == piles.size()) return 0;
//     if(dp[i][M][alice] != -1) return dp[i][M][alice];
//     int ans = alice ? INT_MIN : INT_MAX;
//     int total = 0;

//     for(int X=1; X<=2*M; ++X){
//         if(i+X-1 >= piles.size()) break;
//         total += piles[i+X-1];
//         if(alice)
//             ans = max(ans, total + solveTD(piles, i + X, max(X, M), !alice, dp));
//         else
//             ans = min(ans, solveTD(piles, i + X, max(X, M), !alice, dp));
//     }
//     return dp[i][M][alice] = ans;
// }

// int stoneGameII(vector<int>& piles) {
//     vector<vector<vector<int>>> dp(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(2, -1)));
//     return solveTD(piles, 0, 1, true, dp);
// }
// };

int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<int> suffixSum(n+1, 0);

    // Compute suffix sums (total stones from pile i to end)
    for(int i = n-1; i >= 0; i--) {
        suffixSum[i] = piles[i] + suffixSum[i+1];
    }

    for (int i = n-1; i >= 0; --i) {
        for (int M = 1; M <= n; ++M) {
            for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
                dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][max(M, X)]);
            }
        }
    }

    return dp[0][1];
}

};