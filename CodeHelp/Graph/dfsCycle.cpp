//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool checkCycleDfsHelper(int src, unordered_map<int,bool>& vis, vector<int> adj[], int parent) {
        vis[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!vis[nbr]) {
                bool ans = checkCycleDfsHelper(nbr, vis, adj, src);
                if(ans == true) {
                    return true;
                }
            }
            else if(vis[nbr] == true && nbr != parent) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        //handle disconnected components 
        int n = V;
        bool ans = false;
        unordered_map<int,bool> visited;
        int parent = -1;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                ans = checkCycleDfsHelper(i,visited,adj, parent);
                if(ans) {
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends