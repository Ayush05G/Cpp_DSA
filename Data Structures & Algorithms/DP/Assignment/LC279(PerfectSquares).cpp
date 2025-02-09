class Solution {
public:
    int usingRec(int n) {
        // Base case
        if (n == 0) return 1;
        if (n < 0) return 0;

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);

        while (i <= end) {
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + usingRec(n - perfectSquare);
            if (numberOfPerfectSquares < ans) {
                ans = numberOfPerfectSquares;
            }
            ++i;
        }
        return ans;
    }
    //TC O(n^n)
    //SC 0(1)

    int usingMem(int n,vector<int>&dp){
        if (n == 0) return 1;
        if (n < 0) return 0;
        if(dp[n]!=-1)
        return dp[n];

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);

        while (i <= end) {
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + usingMem(n - perfectSquare,dp);
            if (numberOfPerfectSquares < ans) {
                ans = numberOfPerfectSquares;
            }
            ++i;
        }
        dp[n]=ans;
        return dp[n];

    }
    //TC 0(n)
    //SC O(n)

    int usingTab(int n){
        vector<int>dp(n+1,-1);
        dp[0]=1;
        for (int i=1;i<=n;i++){
            int ans = INT_MAX;
            int start=1;
            int end = sqrt(i);

            while (start <= end) {
            int perfectSquare = start * start;
            int numberOfPerfectSquares = 1 + dp[i - perfectSquare];
            if (numberOfPerfectSquares < ans) {
                ans = numberOfPerfectSquares;
            }
            ++start;
        }
        dp[i]=ans;
        }
        return dp[n];
    }
    //Same complexity as Mem

    int numSquares(int n) {
        // return usingRec(n)-1;
        // vector<int> dp(n + 1, -1);
        // return usingMem(n,dp)-1;
        return usingTab(n)-1;
    }
};