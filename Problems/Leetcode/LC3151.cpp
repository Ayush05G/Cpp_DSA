class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return true;
        for(int i=0;i<n-1;i++){
            int sum= nums[i]+nums[i+1];
            if((sum & 1) == 0)
            return false;
        }  
        return true;      
        
    }
};