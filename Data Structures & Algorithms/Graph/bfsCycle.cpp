//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool cycleDetectionUndirectedBFS(int src,unordered_map<int,bool>& visited,vector<int> adj[]) {
      queue<int> q;
      unordered_map<int,int> parent;
      
      //initial state
      q.push(src);
      visited[src] = true;
      parent[src] = -1;

      //main logic
      while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto nbr: adj[frontNode]) {
          if(!visited[nbr]) {
            q.push(nbr);
            visited[nbr] = true;
            parent[nbr] = frontNode;
          }
          //cycle detection case
          else if(visited[nbr] == true && nbr != parent[frontNode]) {
            //cycle present
            return true;
          } 
        }
      }
      return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool ans = false;
          unordered_map<int,bool> visited;
            int n = V;
          for(int i=0; i<n; i++) {
            if(!visited[i]) {
               ans = cycleDetectionUndirectedBFS(i,visited,adj);
              if(ans == true) {
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