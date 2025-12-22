// Problem - Strongly Connected Components in a Directed Graph using Kosaraju's Algorithm - gfg
// Time Complexity - O(V + E)
// Space Complexity - O(V)

class Solution {
  public:
    void topologicalSort(int node, vector<vector<int>> &adj,
                          vector<bool> &visited, stack<int> &s) {
        visited[node] = true;
        for(int v : adj[node]) {
            if(!visited[v])
                topologicalSort(v, adj, visited, s);
        }
        s.push(node);
    }
    
    void DFS(int node, vector<vector<int>> &adj,
             vector<bool> &visited) {
        visited[node] = true;
        for(int v : adj[node]) {
            if(!visited[v])
                DFS(v, adj, visited);
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        stack<int> s;
        vector<bool> visited(V, false);
        
        // Step 1: Order vertices by finish time
        for(int i = 0; i < V; i++) {
            if(!visited[i])
                topologicalSort(i, adj, visited, s);
        }
        
        // Step 2: Transpose graph
        vector<vector<int>> adj2(V);
        for(int i = 0; i < V; i++) {
            for(int v : adj[i]) {
                adj2[v].push_back(i);
            }
        }
        
        // Step 3: Reset visited
        fill(visited.begin(), visited.end(), false);
        
        // Step 4: Process nodes in stack order
        int scc = 0;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!visited[node]) {
                scc++;
                DFS(node, adj2, visited);
            }
        }
        
        return scc;
    }
};