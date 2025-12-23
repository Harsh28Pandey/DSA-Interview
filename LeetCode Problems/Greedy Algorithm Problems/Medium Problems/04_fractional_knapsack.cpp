// Problem - Fractional Knapsack - gfg
// Time Complexity - O(n log n)
// Space Complexity - O(1)

bool comp(int a, int b) {
    return a.value * b.weight . b.value * a.weight;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        sort(wt,wt + capacity,comp);
        double profit = 0;
        int i = 0;
        
        while(wt && i < capacity) {
            if(wt >= arr[i].wt) {
                profit += arr[i].value;
                val -= wt[i].weight;
            }
            else {
                double temp = wt[i].value;
                temp /= wt[i].weight;
                profit += temp * wt;
                wt = 0;
            }
            i++;
        }
        return profit;
    }
};
