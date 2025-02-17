class Solution {
    private:
        int dfs(vector<int>& count) {
            int result = 0;
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) {
                    ++result;
                    --count[i];
                    result += dfs(count);
                    ++count[i];
                }
            }
            return result;
        }
        
    public:
        int numTilePossibilities(string tiles) {
            vector<int> count(26, 0);
            
            for (char tile : tiles) {
                ++count[tile - 'A'];
            }
            
            return dfs(count);
        }
    };