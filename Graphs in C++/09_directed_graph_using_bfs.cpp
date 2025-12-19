// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclic(int V, vector<int> adj[]) {
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

    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for(int j = 0; j < adj[node].size(); j++) {
            inDegree[adj[node][j]]--;
            if(!inDegree[adj[node][j]])
            q.push(adj[node][j]);
        }
    }
    return count != V;
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