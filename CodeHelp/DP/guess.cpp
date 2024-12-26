class Solution {
public:
    int solveUsingRec(int s, int e) {
        //base case
        if(s >= e) {
            return 0;
        }

        //1 case hum solve krenge 
        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
           ans = min(ans, i + max(solveUsingRec(s,i-1), solveUsingRec(i+1, e)));
        }
        return ans;
    }
    int solveUsingMem(int s, int e,vector<vector<int> >& dp) {
        //base case
        if(s >= e) {
            return 0;
        }
        if(dp[s][e] != -1) {
            return dp[s][e];
        } 

        //1 case hum solve krenge 
        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
           ans = min(ans, i + max(solveUsingMem(s,i-1,dp), solveUsingMem(i+1,e,dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int solveUsingTab(int n) {
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

        for(int s=n; s>=1; s--) {
            for(int e=1; e<=n; e++) {
                if(s >= e) {
                    continue;
                }
                else {
                    int ans = INT_MAX;
                    for(int i=s; i<e; i++) {
                    ans = min(ans, i + max(dp[s][i-1], dp[i+1][e]));
                    }
                    dp[s][e] = ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
       // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingTab(n);
        return ans;
    }
};