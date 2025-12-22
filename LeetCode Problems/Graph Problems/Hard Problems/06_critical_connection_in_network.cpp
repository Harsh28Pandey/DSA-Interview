// Problem - Critical Connections in a Network (1192) - LeetCode
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
public:
    void DFS(int node, int parent, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &bridges, int &count) {
        disc[node] = low[node] = count;
        visited[node] = 1;

        for(int j = 0; j < adj[node].size(); j++) {
            int neighbour = adj[node][j];
            if(neighbour == parent)
            continue;

            else if(visited[neighbour])
            low[node] = min(low[node],low[neighbour]);

            else {
                count++;
                DFS(neighbour,node,adj,disc,low,visited,bridges,count);

                // bridge exists
                low[node] = min(low[node],low[neighbour]);
                if(low[neighbour] > disc[node]) {
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(neighbour);
                    bridges.push_back(temp);
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> bridges;
        vector<int> disc(n); // discovery time
        vector<int> low(n); // low time
        vector<bool> visited(n,0);
        int count = 0;

        DFS(0,-1,adj,disc,low,visited,bridges,count);
        return bridges;
    }
};