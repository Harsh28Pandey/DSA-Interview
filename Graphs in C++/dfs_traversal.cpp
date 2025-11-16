// Time Complexity - O(V + E)
// Space Complexity - O(E)
// where V = vertex and E = edges

#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited) {
    visited[node] = true;
    ans.push_back(node);

    for (int nxt : adj[node]) {
        if (!visited[nxt]) {
            DFS(nxt, adj, ans, visited);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj) {
    int v = adj.size();
    vector<bool> visited(v, false);
    vector<int> ans;

    DFS(0, adj, ans, visited);
    return ans;
}

int main() {
    int n, m;
    cout << "Enter n (nodes) and m (edges): ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Safety check
        if (u >= n || v >= n) {
            cout << "Invalid edge! Node index out of range.\n";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }

    vector<int> result = dfs(adj);

    cout << "DFS Traversal: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}