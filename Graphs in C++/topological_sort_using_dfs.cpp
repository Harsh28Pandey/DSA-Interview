#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s) {
    visited[node] = true;

    for(int j = 0; j < adj[node].size(); j++) {
        if(!visited[adj[node][j]]) {
            DFS(adj[node][j], adj, visited, s);
        }
    }

    // push after visiting all neighbours
    s.push(node);
}

vector<int> topologicalSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> s;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            DFS(i, adj, visited, s);
        }
    }

    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
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

    vector<int> topo = topologicalSort(V, adj);

    cout << "Topological Order:\n";
    for(int node : topo)
        cout << node << " ";
    cout << endl;

    return 0;
}
