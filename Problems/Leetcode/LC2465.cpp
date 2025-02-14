class Solution {
    public:
       int distinctAverages(vector<int>& nums) {
        set<double> uniqueAverages;
        
        while (!nums.empty()) {
            sort(nums.begin(), nums.end());
    
            double minVal = nums[0];
            double maxVal = nums.back();
            
            double avg = (minVal + maxVal) / 2.0;
            uniqueAverages.insert(avg);
            
            nums.erase(nums.begin());  
            nums.erase(nums.end() - 1);  
        }
        
        return uniqueAverages.size();
    }
    };