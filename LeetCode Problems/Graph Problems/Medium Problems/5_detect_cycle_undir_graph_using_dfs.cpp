// Problem - Detect Cycle in an Undirected Graph Using DFS - gfg
// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool cycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;

        for (int next : adj[node]) {

            if (next == parent) 
                continue;

            if (visited[next]) 
                return true;

            if (cycleDetect(next, node, adj, visited))
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // undirected graph
        }

        vector<bool> visited(V, false);

        // Check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (cycleDetect(i, -1, adj, visited)) 
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    bool result = obj.isCycle(V, edges);

    if (result)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}