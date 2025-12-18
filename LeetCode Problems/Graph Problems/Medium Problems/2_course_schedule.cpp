// Problem - Course Schedule II - gfg
// Time Complexity - O(V + E)
// Space Complexity - O(V + E)

class Solution {
  public:
    bool findOrder(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> adj[N];
        vector<int> inDegree(N,0);
        
        for(int i = 0; i < P; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(!inDegree[i])
            q.push(i);
        }
        
        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int j = 0; j < adj[node].size(); j++) {
                inDegree[adj[node][j]]--;
                if(!inDegree[adj[node][j]])
                q.push(adj[node][j]);
            }
        }
        
        vector<int> temp;
        return ans.size() == N ? ans : temp;
    }
};