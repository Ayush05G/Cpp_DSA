class Solution {
  public:
    int maxLen(vector<int>& A) {
        int n=A.size();
        unordered_map<int, int> map;
        int csum = 0;
        int ans = 0; // max length of subarray with 0 sum.
        for(int i = 0; i < n; i++) {
            csum += A[i];
            if(csum == 0) {
                ans = max(ans, i + 1);
            }
            else if(map.find(csum) == map.end()) {
                map[csum] = i;
            }
            else {
                ans = max(ans, i - map[csum]);
            }
        }
        return ans;
    }
};