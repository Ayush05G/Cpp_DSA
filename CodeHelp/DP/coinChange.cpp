class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        //base case
        if(amount == 0) {
            //0 amount create krne k liye kitne coins
            return 0;
        }
        //if amount < 0
        int minCoinAns = INT_MAX;
        //hr amount k liye poore coins k array ko
        //traverse krre h 
        for(int i=0; i<coins.size(); i++) {
            //int amt = amount;
            int coin = coins[i];
            //if coin value > amount value, no need to call recursive function
            //if coin value <= amount value , call recursive fiunction
            if( coin <= amount) {
                //1 coin toh use hogya, amount becomes amount-coins
                //baaki reciursion sambhal lega
                int recursionAns = solve(coins, amount-coin);
                //ho skta h recursionAns valid ho ya fer Invalid 
                //invalid case -> recursionAns -> INT_MAX;
                //valid case -> recursionAns -> not equal to INT_MAX;
                if(recursionAns != INT_MAX) {
                    //valid answer aaaya h 
                    int coinsUsed = 1 + recursionAns;
                    //kya above answer minimum hai
                    minCoinAns = min(minCoinAns, coinsUsed);
                }

            }
        }
    return minCoinAns;
    }//1 d dp

    int solveMem(vector<int>& coins, int amount,vector<int>& dp) {
        if(amount == 0) {
            return 0;
        }
        //step3: check if ans already exists
        if(dp[amount] != -1) {
            return dp[amount];
        }

        int minCoinAns = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            
            int coin = coins[i];
            if( coin <= amount) {
                int recursionAns = solveMem(coins, amount-coin,dp);
                if(recursionAns != INT_MAX) {
                    int coinsUsed = 1 + recursionAns;
                    minCoinAns = min(minCoinAns, coinsUsed);
                }
            }
        }
        //step2: dp ans store and return
        dp[amount] = minCoinAns;
        return dp[amount];
    }

    int solveUsingTab(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);

        dp[0] = 0;

        for(int amt = 1; amt <=amount; amt++) {
            //logic
            int minCoinAns = INT_MAX;
            for(int i=0; i<coins.size(); i++) { 
                int coin = coins[i];
                if( coin <= amt) {
                    int recursionAns = dp[amt-coin];
                    if(recursionAns != INT_MAX) {
                        int coinsUsed = 1 + recursionAns;
                        minCoinAns = min(minCoinAns, coinsUsed);
                    }
                }
            }
            //step2: dp ans store and return
            dp[amt] = minCoinAns;
        }
        return dp[amount];
    }



    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins, amount);
        // if(ans == INT_MAX) {
        //     return -1;
        // }
        // return ans;
        vector<int> dp(amount+1,-1);
        int ans = solveUsingTab(coins,amount);
        if(ans == INT_MAX) {
                return -1;
        }
        return ans;
    }
};