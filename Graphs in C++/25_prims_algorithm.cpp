// Time Compleity - O(E log V)
// Space Complexity - O(V + E)

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<vector<int>>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int,pair<int,int>>, 
            vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>> pq;

        vector<bool> isMST(V, 0);
        vector<int> parent(V);
        int cost = 0;

        pq.push({0, {0, -1}});

        while(!pq.empty()) {
            int weight = pq.top().first;
            int node   = pq.top().second.first;
            int par    = pq.top().second.second;
            pq.pop();

            if(!isMST[node]) {
                isMST[node] = 1;
                cost += weight;
                parent[node] = par;

                for(int j = 0; j < adj[node].size(); j++) {
                    int adjNode = adj[node][j][0];
                    int adjWt   = adj[node][j][1];

                    if(!isMST[adjNode]) {
                        pq.push({adjWt, {adjNode, node}});
                    }
                }
            }
        }
        return cost;
    }
};