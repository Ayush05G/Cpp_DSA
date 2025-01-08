#include <iostream>
#include<unordered_map>
#include<set>
#include<list>
#include<limits.h>
#include<vector>

using namespace std;

class graph {
	public:
	unordered_map<int, list<pair<int,int> > > adjList;

	void addEdge(int u, int v, int wt, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1) {
			adjList[v].push_back({u,wt});
		}
	}

	void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}
          //a -> pair<int,list<pair<int,int> >
          //a.first = u
          //a.second -> nbr of u node -> list <pair<int,int>
          //b -> pair<int,int>
          //b.first -> v;
          //b.second -> weight
  void  bellmanForAlgo(int src, int n) {

    vector<int> dist(n, INT_MAX);
    //intial state 
    dist[src] = 0;

    //n-1 times loop chalao 
    for(int i=0; i<n-1; i++) {
      //hr edge pr jao and relaxaction stp karo
      for(auto a: adjList) {
        for(auto b: a.second) {

          int u = a.first;
          int v = b.first;
          int wt = b.second;
          if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            dist[v] = dist[u] + wt;
          }
        }
      }
    }

    bool negativeCyclePresent = false;

    for(auto a: adjList) {
        for(auto b: a.second) {

          int u = a.first;
          int v = b.first;
          int wt = b.second;
          if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            dist[v] = dist[u] + wt;
            negativeCyclePresent = true;
            break;
          }
        }
      }
    
    if(negativeCyclePresent == true) {
      cout << "-ve cycle present" << endl;
    }
    else {
      cout << "-ve cycle not present" << endl;

      cout << "printing bellman for result: " << endl;
      for(int i=0; i<n; i++) {
        cout << dist[i] << " ";
      }
    }





  }

  void shortestDistanceDijkstra(int src, int n) {
      vector<int> dist(n+1, INT_MAX);
      set<pair<int,int> > st;

      //intial state
      dist[src] = 0;
      st.insert({0,src});

      //main logic 
      while(!st.empty()) {
        auto topElement = *(st.begin());
        int topNodeDistance = topElement.first;
        int topNode = topElement.second;

        //pop this node
        st.erase(st.begin());

        //neighbour pr jao 
        for(auto nbr: adjList[topNode]) {
          //nbr is a pair
          //nbr = {a,b}
          //a -> node
          //b -> wt
          int nbrNode = nbr.first;
          int nbrDistance = nbr.second;
          if(dist[topNode] + nbrDistance < dist[nbrNode]) {
            //2 kaam krne h 
            //distnce array ko update krna h 
            //set ko update krna h 
            auto result = st.find({dist[nbrNode], nbrNode});
            if(result != st.end()) {
              //entry found;
              //remove this entry 
              st.erase(result);
            }
            dist[nbrNode] = dist[topNode] + nbrDistance;
            st.insert({dist[nbrNode], nbrNode});
          }
        }

      }

      cout << "Printing the result" << endl;

      for(int i=0; i<n; i++) {
        cout << dist[i] << " ";
     }
  }

  void floydWarshalAlgo(int n) {
    vector<vector<int> > dist(n, vector<int>(n, 1e9));

    //step1: diagnol pr 0 rakkhdiye 
    for(int i=0; i<n; i++) {
      dist[i][i]= 0;
    }
    //step2: copy all distance from graph to matrix 
    for(auto a: adjList) {
      for(auto b: a.second) {
        int u = a.first;
        int v = b.first;
        int wt = b.second;
        dist[u][v] = wt;
      }
    }
    //main logic of helper node 
    for(int helper=0; helper<n; helper++) {
      for(int u=0; u < n; u++) {
        for(int v=0; v<n; v++) {
            dist[u][v] = min(dist[u][v], dist[u][helper]+dist[helper][v]);
        }
      }
    }

    cout << "Printing Result of FW algo: " << endl;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        cout << dist[i][j] <<", ";
      }
      cout << endl;
    }

  }




};

int main() {
  graph g;

  // g.addEdge(0,1,-1,0);
	// g.addEdge(1,4,2,0);
	// g.addEdge(0,2,4,0);
	// g.addEdge(3,2,5,0);
	// g.addEdge(4,3,-3,0);
	// g.addEdge(1,2,3,0);
	// g.addEdge(1,3,2,0);
	// g.addEdge(3,1,1,0);

  // g.addEdge(0,1,-1,0);
  // g.addEdge(1,0,-2,0);

  g.addEdge(0,2,-2,0);
  g.addEdge(1,0,4,0);
  g.addEdge(1,2,3,0);
  g.addEdge(3,1,-1,0);
  g.addEdge(2,3,2,0);


  //g.bellmanForAlgo(0, 2);
  g.floydWarshalAlgo(4);

  return 0;
}