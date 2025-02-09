#include <iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<limits.h>
using namespace std;

class Graph{
  public:
    unordered_map<int,list<pair<int,int> > > adj;

    void addEdge(int u, int v,int wt, bool direction) {
      //direction = 0 -> undirected edge
      //direction = 1 -> directed edge
      if(direction == 0) {
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
      }
      else {
        adj[u].push_back({v,wt});
      }
    }
    // void printAdjList(int n) {
    //   for(int i=0; i<n; i++) {
    //     cout << i <<": {";
    //     for(auto j: adj[i]) {
    //       cout << j <<", ";
    //     }
    //     cout << "}" << endl;
    //   }
    // }

    // void shortestPathBfs(int src, int dest) {
    //   unordered_map<int,bool> vis;
    //   unordered_map<int,int> parent;
    //   queue<int> q;

    //   //intial state;
    //   q.push(src);
    //   vis[src] = true;
    //   parent[src] = -1;

    //   //main logic 
    //   while(!q.empty()) {
    //     int frontNode = q.front();
    //     q.pop();

    //     for(auto nbr: adj[frontNode]) {
    //       if(!vis[nbr]) {
    //         q.push(nbr);
    //         vis[nbr] = true;
    //         parent[nbr] = frontNode;
    //       }
    //     }
    //   }

    //   //parent array ready

    //   vector<int> path;

    //   int node = dest;

    //   while(node != -1) {
    //     path.push_back(node);
    //     node = parent[node];
    //   }

    //   //reverse path
    //   reverse(path.begin(), path.end());

    //   //print path
    //   cout << "Printing Path: " ;
    //   for(auto i: path) {
    //     cout << i <<"->" ;
    //   }cout << endl;

    // }

    void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
      visited[src] = true;

      for(auto neighbour: adj[src]) {
        if(!visited[neighbour.first] ) {
          topoSortDfs(neighbour.first, visited, ans);
        }
      }

      //while returning, store the node in stack
      //cout << "Pushing " << src << endl;
      ans.push(src);
	}

    void shortestPathDfs(int src) {
      stack<int> topoOrder;
      unordered_map<int,bool> vis;
      //unordered_map<int,int> parent;

      topoSortDfs(src, vis,topoOrder);

      //ab mere paas topo order ka stack ready h 
      int n = topoOrder.size();
      vector<int> dist(n, INT_MAX);

      //intial state maintain
      src =  topoOrder.top();
      topoOrder.pop();

      dist[src] = 0;
      //parent[src] = -1;
      //and src k neighbours k min distance ko update krte ho 
      for(auto nbr: adj[src]) {
        // nbr -> {a,b}
        //a -> node
        //b-> weight
        int node = nbr.first;
        int weightDistance = nbr.second;
        if(dist[src] + weightDistance < dist[node]) {
          dist[node] = dist[src] + weightDistance;
          //parent[node] = src ;
        }
      }

      //main logic 

      while(!topoOrder.empty()) {
        int frontNode = topoOrder.top();
        topoOrder.pop();

        for(auto nbr: adj[frontNode] ) {
            // nbr -> {a,b}
            //a -> node
            //b-> weight
            int node = nbr.first;
            int weightDistance = nbr.second;
            if(dist[frontNode] + weightDistance < dist[node]) {
              dist[node] = dist[frontNode] + weightDistance;
              //parent[node] = frontNode;
            }
        }
      }

      cout <<"Printing Distance array : " << endl;
      for(auto i : dist) {
        cout << i << " ";
      }cout << endl;

      // int dest = 2;
      // cout << endl;
      // while(dest != -1) {
      //   cout << dest <<"<-";
      //   dest = parent[dest];
      // }



    }

};

int main() {
  Graph g;

  // g.addEdge(0,1,0);
  // g.addEdge(1,2,0);
  // g.addEdge(2,3,0);
  // g.addEdge(2,4,0);
  // g.addEdge(4,5,0);
  // g.addEdge(5,3,0);

  g.addEdge(0,1,5,1);
  g.addEdge(0,2,13,1);
  g.addEdge(0,4,3,1);
  g.addEdge(1,2,7,1);
  g.addEdge(1,4,1,1);
  g.addEdge(4,3,6,1);
  g.addEdge(3,2,2,1);

  g.shortestPathDfs(0);

  // int src = 0;
  // int dest = 3;
  // g.shortestPathBfs(src,dest);

  return 0;
}