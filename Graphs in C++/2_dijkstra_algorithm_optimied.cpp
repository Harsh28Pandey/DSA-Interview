// Time Complexity - O(E log V) where E is the number of edges and V is the number of vertices
// Space Complexity - O(V + E) for the adjacency list and O(V) for the distance array

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<bool> explored(V,0);
        vector<int> distance(V,0);
        distance[src] = 0;
        priority_queue<pair<int,int>>, vector<pair<int, int>>, greater<pair<int, int>> p;
        p.push({0,src});
        
        while(!p.empty()) {
            int node = p.top().second;
            p.pop();
            if(explored[node] == 1)
            continue;
            
            explored[node] = 1;
            
            for(int j = 0; j < adj[node].size(); j++) {
                int neighbour = adj[node][j][0];
                int weight = adj[node][j][1];
                if(!explored[neighbour] && (distance[node] + weight < distance[neighbour])) {
                    distance[neighbour] = distance[node] + weight;
                    p.push({distance[neighbour], neighbour});
                }
            }
        }
        return distance;
    }
};