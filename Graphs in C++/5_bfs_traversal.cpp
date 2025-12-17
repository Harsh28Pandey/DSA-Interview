// Time Complexity - O(V + E)
// Space Complexity - O(E)
// where V = vertex and E = edges

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
    int v = adj.size();
    queue<int> q;
    q.push(0);

    vector<bool> visited(v, false);
    visited[0] = true;

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int nxt : adj[node]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter n (number of nodes) and m (number of edges): ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (u >= n || v >= n) {
            cout << "Invalid edge: node index out of range!\n";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);   // For undirected graph
    }

    vector<int> result = bfs(adj);

    cout << "BFS Traversal: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}