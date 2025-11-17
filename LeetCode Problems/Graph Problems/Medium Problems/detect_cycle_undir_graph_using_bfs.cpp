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
    bool BFS(int vertex, vector<int> adj[], vector<bool> &visited) {
        queue<pair<int,int>> q;
        visited[vertex] = 1;
        q.push({vertex,-1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (int nxt : adj[node]) {

                if (nxt == parent) 
                    continue;

                if (visited[nxt])
                    return true;

                visited[nxt] = true;
                q.push({nxt, node});
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (BFS(i, adj, visited))
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
    bool ans = obj.isCycle(V, edges);

    if (ans)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}