//Time Complexity: O(N * Q)

class Solution {
public:
    
    bool isSubarraySpecial(vector<int>& nums, int from, int to) {
        if (from == to) return true;  
        
        for (int i = from; i < to; i++) {
           
            if ((nums[i] & 1) == (nums[i + 1] & 1)) {
                return false;
            }
        }
        return true;
    }
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> answer;
        
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];
            answer.push_back(isSubarraySpecial(nums, from, to));
        }  
        return answer;
    }
};

//Time Complexity: O(N + Q)

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> sameParity(n-1, 0);
        for(int i = 0; i < n-1; i++) {
            sameParity[i] = ((nums[i] & 1) == (nums[i+1] & 1));
        }
        
        // Prefix sum array to count number of same parity pairs
        vector<int> prefix(n, 0);
        for(int i = 0; i < n-1; i++) {
            prefix[i+1] = prefix[i] + sameParity[i];
        }
        
        vector<bool> answer;
    
        for(const auto& query : queries) {
            int from = query[0];
            int to = query[1];
            
            if(from == to) {
                answer.push_back(true);
                continue;
            }
            
              // Check if there are any same parity pairs in range
            int samePairCount = prefix[to] - prefix[from];
            answer.push_back(samePairCount == 0);
        }
        
        return answer;
    }
};