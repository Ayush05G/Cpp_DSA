class Solution {
public:
    vector<int> findAnswer(int n, vector<int> &A) {
        vector<int> result(n);
        
        // For each starting index
        for (int i = 0; i < n; i++) {
            int minLength = 0;
            long long sum = 0;  // Changed to long long for large numbers
            
            // Try different subarray lengths starting from index i
            for (int len = 1; len <= n - i; len++) {
                sum += (long long)A[i + len - 1];  // Cast to long long before addition
                
                // If we found a sum > 0, this is the minimum length for index i
                if (sum > 0) {
                    minLength = len;
                    break;
                }
            }
            
            result[i] = minLength;
        }
        
        return result;
    }
};