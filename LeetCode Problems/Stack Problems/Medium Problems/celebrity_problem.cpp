// Time complexity - O(n)
// Space Complexity - O(n)

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int getCelebrity(vector<vector<int>> arr) {
    int n = arr.size();
    stack<int> s;
    for(int i = 0; i < n; i++) {
        s.push(i);
    }
    while(s.size() > 1) {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if(arr[i][j] == 0) {
            s.push(i);
        }
        else {
            s.push(j);
        }
    }
    int celebrity = s.top();
    for(int i = 0; i < n; i++) {
        if((i != celebrity) && (arr[i][celebrity] == 0) || arr[celebrity][i] == 1) {
            return -1;
        }
    }
    return celebrity;
}

int main() {
    vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};
    int ans = getCelebrity(arr);
    cout << "Celebrity is: " << ans << endl;
    return 0;
}