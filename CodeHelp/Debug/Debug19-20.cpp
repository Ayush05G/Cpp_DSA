#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> getOneComponent(bool** graph, int startingVertex, int v, bool* visited) {
	vector<int> component;
	queue<int> pendingNodes;
	pendingNodes.push(startingVertex);
	visited[startingVertex] = true;

	while(!pendingNodes.empty()){
		int current = pendingNodes.front();
		pendingNodes.pop();
		component.push_back(current);
		for(int i=0; i<v; i++){
			if(graph[current][i] && !visited[i]) {
				pendingNodes.push(i);
				visited[i] = true;
			}
		}

	}
	return component;
}

vector<vector<int>> getAllComponents(bool** graph, int v) {
	vector<vector<int>> result;
	bool* visited = new bool[v]();

	for(int i=0; i<v; i++){
		if(!visited[i]){
			vector<int> component = getOneComponent(graph, i, v, visited);
			result.push_back(component);
		}
	}

	return result;
}


int main() {
    int v, e;
    cin >> v >> e;
    bool** graph = new bool*[v];
    for(int i=0; i<v; i++){
        graph[i] = new bool[v]();
    }

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<vector<int>> components = getAllComponents(graph, v);
    for(int i=0; i<components.size(); i++){
        for(int j=0; j<components[i].size(); j++){
            cout << components[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}