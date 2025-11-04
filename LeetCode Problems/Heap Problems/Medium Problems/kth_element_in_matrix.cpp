// Problem - kth Element in matrix - gfg
// Time Complexity: O(k log n + n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();

        // Min-heap based on matrix values
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>> pq;
        
        // Initialize heap with first element of each row
        for(int i = 0; i < n; i++) {
            pq.push({mat[i][0], {i, 0}});
        }
        
        int ans = -1;
        while(k--) {
            auto element = pq.top();
            pq.pop();
            ans = element.first;
            int i = element.second.first;
            int j = element.second.second;
            
            // Push next element of same row
            if(j + 1 < n) {
                pq.push({mat[i][j + 1], {i, j + 1}});
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50}
    };
    
    int k = 7;
    
    Solution sol;
    int result = sol.kthSmallest(mat, k);
    
    cout << k << "th smallest element in the matrix is: " << result << endl;
    
    return 0;
}