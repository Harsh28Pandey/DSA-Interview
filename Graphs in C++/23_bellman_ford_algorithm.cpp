// Time Complexity - Best Case - O(E)
// Worst Case - O(V * E)
// Space Complexity - O(V)

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    int e = edges.size();

    for(int i = 0; i < V - 1; i++) {
        // relax all the edges
        bool flag = 0;
        for(int j = 0; j < e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] == INT_MAX)
            continue;

            if(dist[u] + wt < dist[v]) {
                flag = 1;
                dist[v] = dist[u] + wt;
            }
        }

        if(!flag)
        return dist;
    }

    // to detect the cycle
    for(int j = 0; j < e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] == INT_MAX)
        continue;

        if(dist[u] + wt < dist[v]) {
            // cycle detected
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }
    return dist;
}