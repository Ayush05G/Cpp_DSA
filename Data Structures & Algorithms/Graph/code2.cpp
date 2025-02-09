class Solution {
public:

    void countBridges(int src, int parent, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis, int timer
    ,vector<vector<int> >& ans, unordered_map<int,list<int> >& adj) {
    //cout << "received call for " << src << endl;
    timer++;
    vis[src] = true;
    tin[src] = timer;
    low[src] = timer;

    //neighbours pe travel krte h 
    for(auto nbr: adj[src]) {
      //kyoki undirected graph h , toh
      //neighbour me parent bhi ho skta h 
      if(nbr == parent) {
        continue;
      }
      else if(!vis[nbr]) {
        //normal trversal karo and check for bridges
        countBridges(nbr, src, tin, low, vis, timer,ans,adj);
        //ab main wapas aaya hu, let do beidge check
        //ye main bhul jata hu  
        low[src] = min(low[src], low[nbr]);

        if(low[nbr] > tin[src]) {
          //brdige exists
          vector<int> temp;
          temp.push_back(src);
          temp.push_back(nbr);
          ans.push_back(temp);
        }
      }
      else {
        //already visited and not parent
        //low time ko update kardo if possible
        low[src] = min(low[src], low[nbr]);
      }
    }


   }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;

        int timer = 0;
        int src = 0;
        int parent = -1;
        vector<int> tin(n);
        vector<int> low(n);
        unordered_map<int,bool> vis;

        //create adjList
        unordered_map<int,list<int> > adj;

        for(auto i: connections ) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        countBridges(src,parent,tin,low, vis, timer,ans,adj);

        return ans;
    }
};