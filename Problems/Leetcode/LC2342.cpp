class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            map<int, vector<int>> summap; 
            int maximal = -1;
            
            for(int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                int sum = 0;
                while(num > 0) {
                    sum += num % 10;
                    num /= 10;
                }
                summap[sum].push_back(nums[i]); 
            }
            
            for(auto& pair : summap) {
                vector<int>& values = pair.second;
                if(values.size() >= 2) {
                    sort(values.begin(), values.end(), greater<int>());
                    maximal = max(maximal, values[0] + values[1]);
                }
            }
            return maximal;
        }
    };