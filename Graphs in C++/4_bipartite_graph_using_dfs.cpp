// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool checkBip(int node, vector<vector<int>> &adj, vector<int> &color) {
        for (int j = 0; j < adj[node].size(); j++) {
            int adjNode = adj[node][j];

            if (color[adjNode] == -1) {
                color[adjNode] = (color[node] + 1) % 2;
                if (!checkBip(adjNode, adj, color))
                    return false;
            }
            else if (color[node] == color[adjNode]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &adj) {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!checkBip(i, adj, color))
                    return false;
            }
        }
        return true;
    }
};

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

    Solution obj;
    cout << obj.isBipartite(V, adj);

    return 0;
}
