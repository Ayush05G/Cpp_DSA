class Solution {
public:
    bool solveRec(string& s, string& p, int i, int j) {
        //base cases
        if(i == s.length() && j == p.length()) {
            //saare characters match hogye h 
            return true;
        }
        if(j == p.length() ) {
            //pattern khatam hogya h, but string khatma nahi hui h 
            return false;
        }
        if(i == s.length()) {
            //agar sarre bchue hue characters * h, toh true nahi toh false;
            for(int k = j; k<p.length(); k++) {
                if(p[k] != '*') {
                    return false;
                }
            }
            //agar yaha pohocha, iska mtlb ssare character * mile p string me 
            return true;
        }
        /// ab yaha main logic aaega 
        //match or not match 
        if(p[j] == '?' || s[i] == p[j]) {
            return solveRec(s,p,i+1,j+1);
        }
        else if(p[j] =='*') {
            // '*' empty string bhi bn skta h, ya fer kuch bhi character bn skta h
            return solveRec(s,p,i+1,j) || solveRec(s,p,i,j+1);
        }
        else {
            //not match
            return false;
        }
    }
    bool solveMem(string& s, string& p, int i, int j,vector<vector<int> >& dp) {
        //base cases
        if(i == s.length() && j == p.length()) {
            //saare characters match hogye h 
            return true;
        }
        if(j == p.length() ) {
            //pattern khatam hogya h, but string khatma nahi hui h 
            return false;
        }
        if(i == s.length()) {
            //agar sarre bchue hue characters * h, toh true nahi toh false;
            for(int k = j; k<p.length(); k++) {
                if(p[k] != '*') {
                    return false;
                }
            }
            //agar yaha pohocha, iska mtlb ssare character * mile p string me 
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        /// ab yaha main logic aaega 
        //match or not match 
        bool ans;
        if(p[j] == '?' || s[i] == p[j]) {
            ans =  solveMem(s,p,i+1,j+1,dp);
        }
        else if(p[j] =='*') {
            // '*' empty string bhi bn skta h, ya fer kuch bhi character bn skta h
            ans =  solveMem(s,p,i+1,j,dp) || solveMem(s,p,i,j+1,dp);
        }
        else {
            //not match
            ans =  false;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    bool solveUsingTab(string s, string p, int m , int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        dp[m][n] = true;

        for(int col = 0; col < n; col++) {
            bool flag = true;
             for(int k = col; k<p.length(); k++) {
                if(p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[m][col] = flag;
        }

        for(int i=m-1; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                bool ans;
                if(p[j] == '?' || s[i] == p[j]) {
                    ans =  dp[i+1][j+1];
                }
                else if(p[j] =='*') {
                    ans =  dp[i+1][j] || dp[i][j+1];
                }
                else {
                    ans =  false;
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    bool solveUsingTabSO(string s, string p, int m , int n) {
        //vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        next[n] = true;

        for(int col = 0; col < n; col++) {
            bool flag = true;
             for(int k = col; k<p.length(); k++) {
                if(p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            next[col] = flag;
        }

        for(int i=m-1; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                bool ans;
                if(p[j] == '?' || s[i] == p[j]) {
                    ans =  next[j+1];
                }
                else if(p[j] =='*') {
                    ans =  next[j] || curr[j+1];
                }
                else {
                    ans =  false;
                }
                curr[j] = ans;
            }
            //shiufting
            next = curr;
        }

        return next[0];
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        //vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
        bool ans = solveUsingTabSO(s,p,m,n);
        return ans;
    }
};