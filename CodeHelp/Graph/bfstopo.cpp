//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
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
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    topoBfs(V, adj, ans);
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