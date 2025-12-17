// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
using namespace std;

bool detectCycle(int node, vector<int> adj[], vector<bool> &path, vector<bool> &visited) {
    visited[node] = 1;
    path[node] = 1;

    // look at adjacent node
    for(int j = 0; j < adj[node].size(); j++) {
        // if neighbour node is already present in my path then cycle is present
        if(path[adj[node][j]]) {
            return 1;
        }

        if(!visited[adj[node][j]] && detectCycle(adj[node][j],adj,path,visited)) {
            return 1;
        }
    }
    path[node] = 0;
    return 0;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> path(V,0);
    vector<bool> visited(V,0);

    for(int i = 0; i < V; i++) {
        if(!visited[i] && detectCycle(i,adj,path,visited)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v) for directed graph:\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if(isCyclic(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}
