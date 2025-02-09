class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >>  > pq;
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int> > dist(row, vector<int>(col, INT_MAX));

        //initial state maintain
        pq.push({0,{0,0}});
        dist[0][0] = 0;

        //dijkstra's logic 

        while(!pq.empty()) {
            pair<int,pair<int,int> > frontNode = pq.top();
            pq.pop();

            int currAbsDifference = frontNode.first;
            int x = frontNode.second.first;
            int y = frontNode.second.second;

            //check for destination
            if(x == row-1 && y == col-1) {
                return dist[x][y];
            }
            else {
                //then do up, down, left, right movement 
                int dx[] = {0,-1,0,1};
                int dy[] = {-1,0,1,0};

                for(int i=0; i<4; i++) {
                    
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if(newX >=0 && newY >= 0 && newX < row && newY < col) {
                        //if new coordinates are safe
                        int newAbsDifference = abs(heights[x][y] - heights[newX][newY]);
                        //as per question, abs difference main MAXIMUM wala store krna chahta hu
                        int newMaxDifference = max(currAbsDifference, newAbsDifference);
                        //as per question, effort/distance main minimum wala store krna chahta hu
                        if(newMaxDifference < dist[newX][newY]) {
                            dist[newX][newY] = newMaxDifference;
                            //jab bhi aap koi new maxDiofference calculate krte h , toh pq me bhi push krnah 
                            pq.push({newMaxDifference,{newX,newY}});
                        }
                    }

                }
            }
        }
        return 0;
    }
};