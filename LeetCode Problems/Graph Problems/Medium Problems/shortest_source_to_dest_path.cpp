// Problem - Shortest Source to Destination Path - gfg
// Time Complexity - O(n * m)
// Space Complexity - O(m + n)

class Solution {
  public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(X == 0 && Y == 0)
        return 0;
        
        if(!A[0][0])
        return -1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        vector<vector<bool>> visited(N,vector<bool> (M,0));
        visited[0][0] = 1;
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();
            
            // up, down, left, right
            for(int k = 0; k < 4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];
                
                if(valid(new_i,new_j,N,M) && A[new_i][new_j] && !visited[new_i][new_j]) {
                    if(new_i == X && new_j == Y)
                    return step + 1;
                    
                    visited[new_i][new_j] = 1;
                    q.push({new_i,{new_j,step + 1}});
                }
            }
        }
        return -1;
    }
};