// Problem - Merge K Sorted Array - gfg
// Time Complexity - O(K * 2 log k)
// Space Complexity - O(K * 2)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Min-heap: stores {value, {row, col}}
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<pair<int, pair<int,int>>>> pq;
        
        int k = mat.size();
        
        // Push first element of each array into heap
        for (int i = 0; i < k; i++) {
            if (!mat[i].empty()) {
                pq.push({mat[i][0], {i, 0}});
            }
        }

        vector<int> ans;
        
        // Extract minimum and insert next element from same array
        while (!pq.empty()) {
            auto element = pq.top();
            pq.pop();

            int val = element.first;
            int row = element.second.first;
            int col = element.second.second;

            ans.push_back(val);

            // If there's a next element in the same row, push it
            if (col + 1 < mat[row].size()) {
                pq.push({mat[row][col + 1], {row, col + 1}});
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Example: 3 sorted arrays
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };
    
    vector<int> merged = sol.mergeArrays(mat);
    
    cout << "Merged Sorted Array: ";
    for (int x : merged) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}