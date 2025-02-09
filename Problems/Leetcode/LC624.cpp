class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            if (arrays.empty()) return 0;
    
            int minFirst = arrays[0][0];
            int maxLast = arrays[0].back();
            int maxDist = 0;
    
            for (int i = 1; i < arrays.size(); ++i) {
                int curFirst = arrays[i][0];
                int curLast = arrays[i].back();
    
                // Check distance between the current sub-array and the previous min/max bounds
                maxDist = max(maxDist, abs(curLast - minFirst));
                maxDist = max(maxDist, abs(curFirst - maxLast));
    
                // Update minFirst and maxLast
                minFirst = min(minFirst, curFirst);
                maxLast = max(maxLast, curLast);
            }
    
            return maxDist;
        }
    };