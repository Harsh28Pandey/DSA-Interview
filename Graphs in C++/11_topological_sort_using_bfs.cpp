#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> inDegree(V,0);

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            inDegree[adj[i][j]]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < V; i++) {
        if(!inDegree[i])
        q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int j = 0; j < adj[node].size(); j++) {
            inDegree[adj[node][j]]--;

            if(inDegree[adj[node][j]] == 0)
            q.push(adj[node][j]);
        }
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

    // If topo size < V, graph has a cycle
    if(topo.size() < V) {
        cout << "Topological sorting not possible (Cycle exists)\n";
    } else {
        cout << "Topological Order:\n";
        for(int node : topo)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}