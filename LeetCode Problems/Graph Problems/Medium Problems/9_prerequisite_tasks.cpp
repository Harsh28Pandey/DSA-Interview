// Problem - Prerequisite Tasks - gfg
// Time Complexity - O(V + E)
// Space Complexity - O(V + E)

class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> adj[N];
        vector<int> inDegree(N,0);
        
        for(int i = 0; i < P; i++) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            inDegree[prerequisites[i].first]++;
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(!inDegree[i])
            q.push(i);
        }
        
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(int j = 0; j < adj[node].size(); j++) {
                inDegree[adj[node][j]]--;
                if(!inDegree[adj[node][j]])
                q.push(adj[node][j]);
            }
        }
        return count == N;
    }
};