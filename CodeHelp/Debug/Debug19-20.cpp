class Solution {
public:
    vector<int>dx = {-1,1,0,0,1,1,-1,-1};
    vector<int>dy = {0,0,-1,1,1,-1,1,-1};
    
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 and x < n and y >= 0 and y < m);
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int cnt = 1;  // Start with 1 for the current cell
                    q.push({i,j});
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();  // Remove the processed element
                        
                        for(int k = 0; k < 8; k++) {
                            int n_x = x + dx[k];
                            int n_y = y + dy[k];
                            if(isValid(n_x, n_y, n, m) and grid[n_x][n_y] == 1) {
                                grid[n_x][n_y] = 0;
                                cnt++;
                                q.push({n_x, n_y});
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};