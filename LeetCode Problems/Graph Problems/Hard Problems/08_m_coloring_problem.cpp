// Problem - M-coloring Problem - gfg
// Time Complexity - O(m * n) ^ n
// Space Complexity - O(n)

bool DFS(int node, vector<int> &color, bool graph[101][101, int m, int n]) {
    for(int i = 0; i < m; i++) {
        bool isPossible = 1;
        for(int j = 0; j < n; j++) {
            if(graph[node][j] && color[j] == i) {
                isPossible = 0;
                break;
            }
        }
        if(isPossible == 0)
        continue;

        color[node] = i;
        isPossible = 1;
        for(int j = 0; j < n; j++) {
            if(graph[node][j] && color[j] == -1) {
                if(!DFS(j,color,graph,m,n)) {
                    isPossible = 0;
                    break;
                }
            }
        }

        if(isPossible)
        return 1;
        color[node] = -1;
    }
    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n,-1);
    for(int i = 0; i < n; i++) {
        if(color[i] == -1 && !DFS(i,color,graph,m,n))
        return 0;
    }
    return 1;
}