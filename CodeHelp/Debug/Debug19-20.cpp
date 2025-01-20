class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> output;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                queue<int> q;
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int g_node = q.front();
                    q.pop();
                    output.push_back(g_node);
                    for (auto it : adj[g_node]) {
                        if (!visited[it]) {
                            visited[it] = true;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return output;
    }
};