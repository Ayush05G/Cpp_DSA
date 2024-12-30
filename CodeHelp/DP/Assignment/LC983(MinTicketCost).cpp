class Solution {
public:
    int mincostTickets_helper(vector<int>& days, vector<int>& costs, int i) {
        if (i >= days.size()) return 0;
        
        // sol for a case
        // 1 Day Pass Taken
        int cost1 = costs[0] + mincostTickets_helper(days, costs, i + 1);
        
        // 7 Day Pass Taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + mincostTickets_helper(days, costs, j);
        
        // 30 Day Pass Taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + mincostTickets_helper(days, costs, j);
        
        return min(cost1, min(cost7, cost30));
    }

    int usingMem(vector<int>& days, vector<int>& costs, int i,vector<int>&dp){
        if (i >= days.size()) return 0;
        if (dp[i]!=-1) return dp[i];
        
        // sol for a case
        // 1 Day Pass Taken
        int cost1 = costs[0] + usingMem(days, costs, i + 1,dp);
        
        // 7 Day Pass Taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + usingMem(days, costs, j,dp);
        
        // 30 Day Pass Taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + usingMem(days, costs, j,dp);
        
        dp[i]= min(cost1, min(cost7, cost30));
        return dp[i];
    }

    int usingTab(vector<int>& days, vector<int>& costs, int i){
        vector<int>dp(days.size()+1,-1);
        dp[days.size()]=0;
        for(int i=days.size()-1;i>=0;i--){
        int cost1 = costs[0] + dp[i+1];
        
        // 7 Day Pass Taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + dp[j];
        
        // 30 Day Pass Taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + dp[j];
        
        dp[i]= min(cost1, min(cost7, cost30));
        }
    return dp[0];
    }
    //TC 0(n^2)
    //SC O(n)
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return mincostTickets_helper(days, costs, 0);
        // vector<int>dp(days.size()+1,-1);
        // return usingMem(days, costs, 0,dp);
        return usingTab(days, costs, 0);
    }
};