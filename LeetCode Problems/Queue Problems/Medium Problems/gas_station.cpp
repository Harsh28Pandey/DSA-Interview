// Problem - Gas Station (134) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for(int val : gas) {
            totalGas += val;
        }
        for(int val : cost) {
            totalCost += val;
        }
        if(totalGas < totalCost) {
            return -1;
        }
        
        // unique solution always exists
        int start = 0, currGas = 0;
        for(int i = 0; i < gas.size(); i++) {
            currGas += (gas[i] - cost[i]);
            if(currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }
        return start;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> gas  = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    
    int result = sol.canCompleteCircuit(gas, cost);
    
    if(result == -1) {
        cout << "No solution exists." << endl;
    } else {
        cout << "Starting station index: " << result << endl;
    }
    
    return 0;
}
