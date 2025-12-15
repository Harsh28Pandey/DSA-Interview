// Problem - Covid Spread - gfg
// Time Complexity - O(n * m)
// Space Complexity - O(n * m)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int r;
    int c;
    
    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
  
    int helpaterp(vector<vector<int>> hospital) {
        // code here
        r = hospital.size();
        c = hospital[0].size();
        queue<pair<int,int>> q; // bfs used
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(hospital[i][j] == 2)
                q.push(make_pair(i,j));
            }
        }
        
        int timer = 0;
        while(!q.empty()) {
            timer++;
            int currPatient = q.size();
            
            while(currPatient--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int k = 0; k < 4; k++) {
                    if(valid(i + row[k],j + col[k]) && hospital[i + row[k]][j + col[k]]) {
                        hospital[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k],j + col[k]));
                    }
                }
            }
        }
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(hospital[i][j] == 1) {
                    return -1;
                }
            }
        }
        return timer - 1;
    }
};

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int r, c;
        cout << "Enter rows and columns: ";
        cin >> r >> c;
        
        vector<vector<int>> hospital(r, vector<int>(c));
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> hospital[i][j];
            }
        }
        
        Solution obj;
        cout << obj.helpaterp(hospital) << endl;
    }
    
    return 0;
}