class Solution {
public:

int solveTD(vector<int>& sv, int i, vector<int>& dp){
    if(i==sv.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans = INT_MIN;
    int total = 0;
    for(int x = 1; x <= 3; ++x){
        if(i + x - 1 >= sv.size()) break;
        total += sv[i + x - 1];
        ans = max(ans, total - solveTD(sv, i + x, dp));
    }
    return dp[i] = ans;
}

int solveBU(vector<int>& sv) {
    vector<int> dp(sv.size() + 1, 0);
    for(int i = sv.size() - 1; i >= 0; --i) {
        int ans = INT_MIN;
        int total = 0;
        for(int x = 1; x <= 3; ++x) {
            if(i + x - 1 >= sv.size()) break;
            total += sv[i + x - 1];
            ans = max(ans, total - dp[i + x]);
        }
        dp[i] = ans;
    }
    return dp[0];
}

string stoneGameIII(vector<int>& stoneValue) {
    // int ans = solve(stoneValue, 0); // A-B

    // vector<int> dp(stoneValue.size() + 1, -1);
    // int ans = solveTD(stoneValue.size(), 0, dp); // A-B

    int ans = solveBU(stoneValue);

    if(ans > 0) return "Alice";
    if(ans < 0) return "Bob";
    return "Tie";
}
};