class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballColors;  // ball -> color
        unordered_map<int,int> colorCount;  // color -> count
        vector<int> output(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            
            // Remove previous color if ball was colored
            if (ballColors.count(ball)) {
                int prevColor = ballColors[ball];
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);
                }
            }
            
            ballColors[ball] = color;
            colorCount[color]++;
            
            output[i] = colorCount.size();
        }
        
        return output;
    } 
    };