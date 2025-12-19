// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int V, vector<vector<int>> &adj) {
    vector<int> color(V, -1);
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++) {
                    int adjNode = adj[node][j];

                    if (color[adjNode] == -1) {
                        color[adjNode] = (color[node] + 1) % 2;
                        q.push(adjNode);
                    } else if (color[node] == color[adjNode]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    if (isBipartite(V, adj))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is NOT Bipartite";

    return 0;
}