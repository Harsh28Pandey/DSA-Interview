// Problem - Parallel Course III (2050) - LeetCode
// Time Complexity - O(V + E)
// Space Complexity - O(V + E)

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n];

        for(int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }

        vector<int> inDeg(n,0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                inDeg[adj[i][j]]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!inDeg[i])
            q.push(i);
        }

        vector<int> courseTime(n,0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int j = 0; j < adj[node].size(); j++) {
                inDeg[adj[node][j]]--;
                if(!inDeg[adj[node][j]])
                q.push(adj[node][j]);

                courseTime[adj[node][j]] = max(courseTime[adj[node][j]], courseTime[node] + time[node]);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans,courseTime[i] + time[i]);
        }
        return ans;
    }
};