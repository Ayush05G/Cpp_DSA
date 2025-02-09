//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    
    void topoDfs(int src, unordered_map<int,bool>& vis, vector<int> adj[], vector<int>& ans) {
    
        vis[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!vis[nbr]) {
                topoDfs(nbr,vis,adj,ans);
            }
        }
        
        //backtrack
        ans.push_back(src);
        
    }
    
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_map<int,bool> visited;
	    int n = V;
	    vector<int> ans;
	    
	    for(int i=0; i<n; i++) {
	        if(!visited[i]) {
	            topoDfs(i,visited,adj,ans);
	        }
	    }
	    //reverse the ordering
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends