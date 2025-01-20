#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Data structure to store a graph edge
struct Edge {
    int src, dest;
};

// Class to represent a graph object
class Graph
{ 
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to N elements of type vector<int>
        adjList.resize(N);
 
        // add edges to the directed graph
        for (auto &edge: edges)
        {
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// Data structure to store a Disjoint Set
class DisjointSet
{
    unordered_map<int, int> parent;

public:
    // perform MakeSet operation
    void MakeSet(int N)
    {
        // create N disjoint sets (one for each vertex)
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
 
    // Find the root of the set in which element k belongs
    int Find(int k)
    {
        // if k is root
        if (parent[k] == k) {
            return k;
        }
 
        // recur for parent until we find the root
        return Find(parent[k]);
    }
 
    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find the root of the sets in which elements
        // x and y belongs
        int x = Find(a);
        int y = Find(b);
 
        parent[x] = y;
    }
};

bool findCycle(Graph const &graph, int n)
{
    // initialize Main class
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.MakeSet(n);
 
    // consider every edge (u, v)
    for (int u = 0; u < n; u++)
    {
        // Recur for all adjacent vertices
        for (int v: graph.adjList[u])
        {
            // find the root of the sets to which elements `u` and `v` belongs
            int x = ds.Find(u);
            int y = ds.Find(v);
 
            // if both `u` and `v` have the same parent, the cycle is found
            if (x == y) {
                return true;
            }
            else {
                ds.Union(x, y);
            }
        }
    }
 
    return false;
}

int main()
{
    // initialize edges as per the above diagram
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}
    };
 
    // total number of nodes in the graph
    int N = 5;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // check if the graph contains a cycle
    if (findCycle(graph, N)) {
        cout << "The graph contains a cycle";
    }
    else {
        cout << "The graph doesn't contain any cycle";
    }
 
    return 0;
}