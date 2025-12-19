// Problem - Euler Circuit and Path - gfg
// Time Complexity - O(V + E)
// Space Complexity - O(V)

class Solution {
  public:
    void DFS(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = 1;
        for(int j = 0; j < adj[node].size(); j++) {
            if(!visited[adj[node][j]])
            DFS(adj[node][j],adj,visited);
        }
    }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        vector<int> deg(V,0);
        int oddDegree = 0;
        for(int i = 0; i < V; i++) {
            deg[i] = adj[i].size();
            if(deg[i] % 2)
            oddDegree++;
        }
        
        if(oddDegree != 2 && oddDegree != 0) {
            return 0;
        }
        
        vector<bool> visited(V,0);
        for(int i = 0; i < V; i++) {
            if(deg[i]) {
                DFS(i,adj,visited);
                break;
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(deg[i] && !visited[i])
            return 0;
        }
        
        if(oddDegree == 0)
        return 2;
        else 
        return 1;
    }
};