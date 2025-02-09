//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long mod = 1000000007;
    long long solveRec(int n, int k) {
        //base case
        if(n == 1) {
            return k;
        }
        if(n == 2) {
            return (k + k*(k-1));
        }
        
        int ans = (k-1) * (solveRec(n-1,k) + solveRec(n-2,k));
        return ans;
    }
    //1D dp
    long long  solveMem(int n, long long k,vector<long long >& dp) {
        //base case
        if(n == 1) {
            return k % mod;
        }
        if(n == 2) {
            return (k + k*(k-1)) % mod;
        }
        
        if(dp[n] != -1) {
            return dp[n]%mod;
        }
        long long ans =((k-1)*((solveMem(n-1,k,dp)%mod + solveMem(n-2,k,dp)%mod)%mod))%mod;
        dp[n] = ans;
        return dp[n];
    }
    
    long long solveUsingTab(int n, long long k ) {
        vector<long long  > dp(n+1,0);
        
        dp[1] = k % mod;
        dp[2] =  (k + k*(k-1)) % mod;
        
        for(int i=3; i<=n; i++) {
            long long ans =((k-1)*((dp[i-1]%mod + dp[i-2]%mod)%mod))%mod;
            dp[i] = ans;
        }
        
        return dp[n];
    }
    
    long long solveUsingTabSO(int n, long long k ) {
        
        long long prev2 = k % mod;
        
        if(n==1)
            return prev2;
            
        long long prev1 =  (k + k*(k-1)) % mod;
        
        if(n==2)
            return prev1;
        
        for(int i=3; i<=n; i++) {
            long long curr =((k-1)*((prev1%mod + prev2%mod)%mod))%mod;
            //shifting
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    long long countWays(int n, int k){
        //return solveRec(n,k);
        //vector<long long  > dp(n+1,-1);
        long long newK = k;
        return solveUsingTabSO(n,newK);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends