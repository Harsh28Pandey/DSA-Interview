// Time Complexity - O(V * V)
// Space Complexity - O(V)

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &adj, int src) {
        // Code here
        vector<bool> explored(V,0);
        vector<int> distance(V,INT_MAX);
        distance[src] = 0;
        int count = V;
        
        while(count--) {
            int node = -1, value = INT_MAX;
            for(int i = 0; i < V; i++) {
                if(!explored[i] && value > distance[i]) {
                    node = i;
                    value = distance[i];
                }
            }
            
            explored[node] = 1;
            for(int j = 0; j < adj[node].size(); j++) {
                int neighbour = adj[node][j][0];
                int weight = adj[node][j][1];
                
                if(!explored[neighbour] && (distance[node] + weight < distance[neighboir])) {
                    distance[neighbour] = distance[node] + weight;
                }
            }
        }
        return distance;
    }
};