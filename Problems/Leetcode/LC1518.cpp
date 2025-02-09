class Solution {
public:
    int numWaterBottles(int n, int k) {
        int ans = n;
        while(n >= k){
            ans += n / k;
            n = n%k + n/k;
        }
        return ans;
    }
};