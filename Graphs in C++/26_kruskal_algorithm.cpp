// Time Complexity - O(V log E)
// Space Complexity - O(V + E)

class Solution {
  public:
    int findParent(int u, vector<int> &parent) {
        if(u == parent[u])
        return u;
        
        return parent[u] = findParent(parent[u],parent);
    }
    
    void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = findParent(u,parent);
        int pv = findParent(v,parent);
        
        if(rank[pu] > rank[pv])
        parent[pv] = pu;
        
        else if(rank[pu] < rank[pv])
        parent[pu] = pv;
        
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> parent(V);
        vector<int> rank(V, 0);
        
        for(int i = 0; i < V; i++)
            parent[i] = i;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>> > pq;

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            pq.push({wt, {u, v}});
        }

        int cost = 0;

        while(!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            if(findParent(u, parent) != findParent(v, parent)) {
                cost += weight;
                unionByRank(u, v, parent, rank);
            }
        }
        return cost;
    }
};