class Solution {
public:
    bool dfs(int source , int destination , vector<int> adj[] , vector<int> &vis)
    {
        vis[source]=1;
        if(source==destination)
        {
            return true;
        }
        for(auto a:adj[source])
        {
            if(!vis[a])
            {
                if(dfs(a,destination , adj , vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]); 
            adj[edges[i][0]].push_back(edges[i][1]);            
        }
        return dfs(source , destination , adj , vis);
    }
};