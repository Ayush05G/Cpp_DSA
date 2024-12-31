class Solution {
public:
    int solve(string s1, string s2, int i, int j){
        int cost = 0;
        if(i == s1.size() || j == s2.size()){
            for(int k=i; k<s1.size();k++) cost+=s1[k];
            for(int k=j; k<s2.size();k++) cost+=s2[k];
            return cost;
        }
        else if(s1[i] == s2[j])
            cost = solve(s1, s2, i + 1, j + 1);
        else {
            int cost1 = s1[i] + solve(s1, s2, i + 1, j);
            int cost2 = s2[j] + solve(s1, s2, i, j + 1);
            cost = min(cost1, cost2);
        }
        return cost;
    }

     int solveTD(string s1, string s2, int i, int j,vector<vector<int>>&dp){
        int cost = 0;
        if(dp[i][j]!=-1) 
        return dp[i][j];
        if(i == s1.size() || j == s2.size()){
            for(int k=i; k<s1.size();k++) cost+=s1[k];
            for(int k=j; k<s2.size();k++) cost+=s2[k];
            return cost;
        }
        else if(s1[i] == s2[j])
            cost = solveTD(s1, s2, i + 1, j + 1,dp);
        else {
            int cost1 = s1[i] + solveTD(s1, s2, i + 1, j,dp);
            int cost2 = s2[j] + solveTD(s1, s2, i, j + 1,dp);
            cost = min(cost1, cost2);
        }
        return dp[i][j]=cost;
    }

    int solveBU(string s1, string s2, int i, int j){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        for(int i=s1.size()-1;i>=0;--i){
            dp[i][s2.size()]=s1[i]+dp[i+1][s2.size()];
        }
        for(int i=s2.size()-1;i>=0;--i){
            dp[s1.size()][i]=s2[i]+dp[s1.size()][i+1];
        }

        for (int x = s1.size() - 1; x >= 0; --x) {
    for (int y = s2.size() - 1; y >= 0; --y) {
        int cost = 0;
        if (s1[x] == s2[y]) {
            cost = dp[x + 1][y + 1];
        } else {
            int cost1 = s1[x] + dp[x + 1][y];
            int cost2 = s2[y] + dp[x][y + 1];
            cost = min(cost1, cost2);
        }
        dp[x][y] = cost;
    }
    }
        return dp[0][0]+1;
}

    int minimumDeleteSum(string s1, string s2) {
        // return solve(s1, s2, 0, 0);
        // vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return solveTD(s1,s2,0,0,dp);
        return solveBU(s1, s2, 0, 0);
    }
};
