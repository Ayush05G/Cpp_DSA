class Solution {
public:
    bool findPairs(vector<int>& a) {
        int n= a.size();
        unordered_map<int, bool> map;
        // pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = a[i] + a[j];
                if (map.find(sum) != map.end()) {
                    return true;
                } else {
                    map[sum] = true;
                }
            }
        }
        return false;
    }
};
