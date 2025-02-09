//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void topoBfs(int n, vector<int> adj[],vector<int>& ans) {
	    unordered_map<int,int> indegree;
	    queue<int> q;
	    
	    //prepare indegree map 
	    for(int src=0; src<n; src++) {
	        for(auto nbr: adj[src]) {
	            //src-> nbr
	            indegree[nbr]++;
	        }
	    }
	    
	    //check for indegree 0 and push in q
	    //maintain insitial state in q
	    for(int i=0; i<n; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    //main logic 
	    while(!q.empty()) {
	        int frontNode = q.front();
	        ans.push_back(frontNode);
	        q.pop();
	        
	        //kyoki frontNode graph se hatt chuki h
	        //update the indegree of its children accordingly 
	        for(auto nbr: adj[frontNode]) {
	            //remove frontNode->nbr
	            indegree[nbr]--;
	            if(indegree[nbr] == 0) {
	                q.push(nbr);
	            }
	        }
	        
	    }
	}
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> ans;
        topoBfs(V,adj,ans);
        
        if(ans.size() == V) {
            //all nodes reached, no cycle 
            return false;
        }
        else {
            //cycle present
            return true;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends