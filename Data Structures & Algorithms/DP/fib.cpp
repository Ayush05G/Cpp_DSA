class Solution {
public:
    //recursion
    int solveRec(int n) {
        //base case
        if(n==0) {
            return 0;
        } 
        if(n == 1) {
            return 1;
        }

        int ans = solveRec(n-1) + solveRec(n-2);
        return ans;
        //recursive relation
    }
    //top-down approach 
    // type of dp -> 1-d dp ->dp array - 1d
    int solveRecMem(int n, vector<int>& dp) {
        //base case
        if(n==0) {
            return 0;
        } 
        if(n == 1) {
            return 1;
        }
        //step3: base case k baad,check  if ans alreadyv exist in dp or not
        if(dp[n] != -1) {
            return dp[n];
        }

        //step2: store and return the dp array 
        dp[n] = solveRecMem(n-1,dp) + solveRecMem(n-2,dp);
        return dp[n];
        //recursive relation
    }

    //approach 3: tabultaion / Bottom-Up
    int solveUsingTab(int n) {
        //step1: create dp array
        vector<int> dp(n+1, -1);
        //step2: base case analyse, base case cop[y paste] , dp update
        if(n==0) {
            return 0;
        } 
        if(n == 1) {
            return 1;
        }
        dp[0] = 0;
        dp[1] = 1;
        //step3: chech paramater range, rverse it and run a loop over it
        //recursion -> n-> 0;
        //reverse -> 0 -> n
        for(int i=2; i<=n; i++) {
            ///copy paste
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int solveUsingTabSpaceOptimised(int n) {
        //step1: create dp array
        //vector<int> dp(n+1, -1);
        //step2: base case analyse, base case cop[y paste] , dp update
        if(n==0) {
            return 0;
        } 
        if(n == 1) {
            return 1;
        }
        //dp[0] = 0;
        int prev = 0;
        //dp[1] = 1;
        int curr = 1;
        //step3: chech paramater range, rverse it and run a loop over it
        //recursion -> n-> 0;
        //reverse -> 0 -> n
        for(int i=2; i<=n; i++) {
            int ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        return curr;
    }

    int fib(int n) {
        //step1: create dp array and pass
        // vector<int> dp(n+1, -1);
        // solveRecMem(n,dp);
        return solveUsingTabSpaceOptimised(n);
    }
};