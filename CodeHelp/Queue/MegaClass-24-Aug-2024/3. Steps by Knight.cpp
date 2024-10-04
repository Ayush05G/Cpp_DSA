class Solution 
{
    public:
    bool explore(pair<int,int>&front, pair<int,int>&dest, queue<pair<int,int>>&q, vector<vector<bool>>&vis, int &N){
        int x[] = {-1, -1, 1, 1, 2, 2, -2, -2};
        int y[] = {2, -2, 2, -2, 1, -1, 1, -1};
        
        for(int i=0;i<8;i++){
            // exploring my children
            int newX = front.first + x[i];
            int newY = front.second + y[i];
            
            // if out of bound or already visited, then its not the
            // child of current node.
            if(newX < 0 || newX >= N || newY < 0 || newY >= N || vis[newX][newY])
                continue;
            
            if(make_pair(newX, newY) == dest) return true;
            
            q.push({newX, newY});
            vis[newX][newY] = true;
        }
        return false; // I have not reached to dest yet
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
    {
        // 1. convert to 0-based indexing
        pair<int,int>src = {KnightPos[0] - 1, KnightPos[1] - 1};
        pair<int,int>dest = {TargetPos[0] - 1, TargetPos[1] - 1};
        
        if(src == dest) return 0;
        
        queue<pair<int,int>>q;
        q.push(src);
        q.push({-1, -1}); // kind of nullptr
        vector<vector<bool>>vis(N, vector<bool>(N, false));
        vis[src.first][src.second] = true;
        
        int step = 1;
        
        // my normal level-order traversal
        while(!q.empty()){
            auto front = q.front(); q.pop();
            
            if(front == make_pair(-1, -1)){
                step++;
                if(!q.empty())
                    q.push({-1, -1});
            }
            else {
                if(explore(front, dest, q, vis, N))
                    return step;
            }
        }
        return -1;
    }
};