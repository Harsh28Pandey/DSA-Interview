// Problem - Circle of Strings - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
  public:
    void DFS(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = 1;
        for(int j = 0; j < adj[node].size(); j++) {
            if(!visited[adj[node][j]])
            DFS(adj[node][j],adj,visited);
        }
    }
  
    int isCircle(vector<string> &arr) {
        // code here
        int n = arr.size();
        vector<int> adj[26];
        vector<int> inDeg(26,0);
        vector<int> outDeg(26,0);
        
        for(int i = 0; i < n; i++) {
            string temp = arr[i];
            int u = temp[0] - 'a';
            int v = temp[temp.size() - 1] - 'a';
            adj[u].push_back(v);
            outDeg[u]++;
            inDeg[v]++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(inDeg[i] != outDeg[i])
            return 0;
        }
        
        vector<bool> visited(26,0);
        int node = arr[0][0] - 'a';
        DFS(node,adj,visited);
        
        for(int i = 0; i < 26; i++) {
            if(inDeg[i] && !visited[i])
            return 0;
        }
        return 1;
    }
};