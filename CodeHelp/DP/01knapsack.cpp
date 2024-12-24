//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solveUsingRec(vector<int>& val, vector<int>& wt, int capacity, int index) {
        //base case
        //single item
        if(index == 0) {
            if(wt[0] <= capacity) {
                return val[0];
            }
            else {
                return 0;
            }
        }
        
        //inc/excl patter
        int incl = 0;
        if(wt[index] <= capacity) {
            incl = val[index] + solveUsingRec(val,wt,capacity-wt[index], index-1);
        }
        int excl = 0 + solveUsingRec(val,wt,capacity,index-1);
        int finalAns = max(incl,excl);
        return finalAns;
    }//2D DP
    //top-down approach
    int solveUsingMem(vector<int>& val, vector<int>& wt, int capacity, int index, vector<vector<int> >& dp) {
        //base case
        //single item
        if(index == 0) {
            if(wt[0] <= capacity) {
                return val[0];
            }
            else {
                return 0;
            }
        }
        //step3: check if ans already existts
        if(dp[capacity][index] != -1) {
            return dp[capacity][index];
        }
        
        //inc/excl patter
        int incl = 0;
        if(wt[index] <= capacity) {
            incl = val[index] + solveUsingMem(val,wt,capacity-wt[index], index-1,dp);
        }
        int excl = 0 + solveUsingMem(val,wt,capacity,index-1,dp);
        //ans return and store 
        dp[capacity][index] = max(incl,excl);
        return dp[capacity][index];
    }
    //bottom-up approach
    int solveUsingTab(int capacity, vector<int>& wt, vector<int>& val) {
        //step1: create dp array 
        int n = val.size();
        vector<vector<int> > dp(capacity+1, vector<int>(n, 0));
        //step2: analyse base case
        for(int w=wt[0]; w<=capacity; w++) {
            dp[w][0] =  val[0];
        }
        //step3: paramter -> range -> reverse -> copy paste logic 
        //recursion 
        //capacity -> [ W to 0 ]
        //index -> [ n-1 to 0 ]
        for(int weight=0; weight<=capacity; weight++) {
            for(int index=1; index<=n-1; index++) {
                int incl = 0;
                if(wt[index] <= weight) {
                    incl = val[index] + dp[weight-wt[index]][index-1];
                }
                int excl = 0 + dp[weight][index-1];
                //ans return and store 
                dp[weight][index] = max(incl,excl);
            }
        }
        
        //ans return 
        return dp[capacity][n-1];

    }
    
    int solveUsingTabSO(int capacity, vector<int>& wt, vector<int>& val) {
        //step1: create dp array 
        int n = val.size();
        // vector<vector<int> > dp(capacity+1, vector<int>(n, 0));
        vector<int> prev(capacity+1, 0);
        vector<int> curr(capacity+1, 0);
        //step2: analyse base case
        for(int w=wt[0]; w<=capacity; w++) {
            prev[w] =  val[0];
        }
        //step3: paramter -> range -> reverse -> copy paste logic 
        //recursion 
        //capacity -> [ W to 0 ]
        //index -> [ n-1 to 0 ]
        for(int index=1; index<=n-1; index++) {
            for(int weight=0; weight<=capacity; weight++) {
                int incl = 0;
                if(wt[index] <= weight) {
                    incl = val[index] + prev[weight-wt[index]];
                }
                int excl = 0 + prev[weight];
                //ans return and store 
                curr[weight] = max(incl,excl);
            }
            //shift
            prev = curr;
        }
        
        //ans return 
        return prev[capacity];

    }
    
    int solveUsingTabSO2(int capacity, vector<int>& wt, vector<int>& val) {
        int n = val.size();
       
        vector<int> curr(capacity+1, 0);
        for(int w=wt[0]; w<=capacity; w++) {
            curr[w] =  val[0];
        }

        for(int index=1; index<=n-1; index++) {
            for(int weight=capacity; weight>=0; weight--) {
                int incl = 0;
                if(wt[index] <= weight) {
                    incl = val[index] + curr[weight-wt[index]];
                }
                int excl = 0 + curr[weight];
                curr[weight] = max(incl,excl);
            }
        }
        
        //ans return 
        return curr[capacity];
    }
    
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int capacity = W;
        int n = val.size();
        int index = n - 1;
        //return solveUsingRec(val,wt,capacity,index);
        //step1: create dp array 
        // vector<vector<int> > dp(capacity+1, vector<int>(n, -1));
        // return solveUsingMem(val,wt,capacity,index,dp);
        return solveUsingTabSO2(capacity,wt,val);
        
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends