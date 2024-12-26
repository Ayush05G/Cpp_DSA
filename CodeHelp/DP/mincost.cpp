class Solution {
public:
    int solveUsingRec(vector<int>& arr, map<pair<int,int>, int>& maxi, int s,int e) {
        //base case
        if(s >= e) {
            return 0;
        }
        //1 case solve, baaki recursion
        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            int leftRangeKaMax = maxi[{s,i}];
            int rightRangeKaMax = maxi[{i+1, e}];
            int NonLeafValue = leftRangeKaMax * rightRangeKaMax;

            ans  = min(ans, NonLeafValue + solveUsingRec(arr,maxi,s,i) + solveUsingRec(arr,maxi,i+1,e));
        }
        return ans;
    }

    int solveUsingMem(vector<int>& arr, map<pair<int,int>, int>& maxi, int s,int e,vector<vector<int> >& dp) {
        //base case
        if(s >= e) {
            return 0;
        }
        if(dp[s][e] != -1) {
            return dp[s][e];
        }

        //1 case solve, baaki recursion
        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            int leftRangeKaMax = maxi[{s,i}];
            int rightRangeKaMax = maxi[{i+1, e}];
            int NonLeafValue = leftRangeKaMax * rightRangeKaMax;

            ans  = min(ans, NonLeafValue + solveUsingMem(arr,maxi,s,i,dp) + solveUsingMem(arr,maxi,i+1,e,dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int solveUsingTab(vector<int> arr, map<pair<int,int> , int> maxi) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int s=n-1; s>=0; s--) {
            for(int e=0; e<=n-1; e++) {
                if(s >= e) {
                    continue;
                }
                else {
                    int ans = INT_MAX;
                    for(int i=s; i<e; i++) {
                        int leftRangeKaMax = maxi[{s,i}];
                        int rightRangeKaMax = maxi[{i+1, e}];
                        int NonLeafValue = leftRangeKaMax * rightRangeKaMax;

                        ans  = min(ans, NonLeafValue + dp[s][i] + dp[i+1][e]);
                    }
                    dp[s][e] = ans;
                }
            }
        }
    return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map< pair<int,int>, int > maxi;

        //loop for all the pairs for range 
        int n = arr.size();

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(i == j) {
                    maxi[{i,j}] = arr[i];
                }
                else {
                    maxi[{i,j}] = max( maxi[{i,j-1}], arr[j] );
                }
            }
        }
        int s = 0;
        int e = n-1;
        //vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingTab(arr,maxi);
        return ans;
    }
};