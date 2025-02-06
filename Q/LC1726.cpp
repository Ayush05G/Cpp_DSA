class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }
        int answer = 0;
        for (auto& [product, count] : productCount) {
            answer += count*(count - 1)*4;
        }
        return answer;
    }
};