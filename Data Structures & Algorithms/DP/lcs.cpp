class Solution {
public:
    int solveUsingRec(string text1, string text2, int i, int j) {
        //base case
        if(i >= text1.length()) {
            return 0;
        }
        if(j >= text2.length()) {
            return 0;
        }
        int ans = 0;
        //match
        if(text1[i] == text2[j]) {
            ans = 1 + solveUsingRec(text1, text2, i+1, j+1);
        }
        else {
            //no match
            ans = 0 + max(solveUsingRec(text1,text2,i+1,j), solveUsingRec(text1,text2,i,j+1));
        }
        return ans;
    }///2d dp

    int solveUsingMem(string& text1, string& text2, int i, int j, vector<vector<int> >& dp) {
        //base case
        if(i >= text1.length()) {
            return 0;
        }
        if(j >= text2.length()) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        //match
        if(text1[i] == text2[j]) {
            ans = 1 + solveUsingMem(text1, text2, i+1, j+1,dp);
        }
        else {
            //no match
            ans = 0 + max(solveUsingMem(text1,text2,i+1,j,dp), solveUsingMem(text1,text2,i,j+1,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }///2d dp

    int solveUsingTab(string text1, string text2) {
        vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, 0));

        for(int i = text1.length()-1; i>=0; i--) {
           for(int j=text2.length()-1; j>=0; j--) {
                int ans = 0;
                //match
                if(text1[i] == text2[j]) {
                    ans = 1 + dp[i+1][j+1];
                }
                else {
                    //no match
                    ans = 0 + max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
           } 
        }
        return dp[0][0];
    }

    int solveUsingTabSO(string text1, string text2) {
        //vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        vector<int> prev(text2.length()+1, 0);
        vector<int> curr(text2.length()+1, 0);

        for(int i = text1.length()-1; i>=0; i--) {
           for(int j=text2.length()-1; j>=0; j--) {
                int ans = 0;
                //match
                if(text1[i] == text2[j]) {
                    ans = 1 + prev[j+1];
                }
                else {
                    //no match
                    ans = 0 + max(prev[j], curr[j+1]);
                }
                curr[j] = ans;
           } 
           //shift
           prev = curr;
        }
        return prev[0];
    }


    int longestCommonSubsequence(string text1, string text2) {
        int i =0;
        int j = 0;
        //vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        return solveUsingTabSO(text1,text2);
    }
};