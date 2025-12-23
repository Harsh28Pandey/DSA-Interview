// Problem - Shop in Candy Store - gfg
// Time Complexity - O(n log n)
// Space Complexity - O(1)

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        sort(prices,prices + n);
        int minAmount = 0, maxAmount = 0;
        int i = 0, j = n - 1;
        
        while(i <= j) {
            minAmount += prices[i];
            i++;
            j -= k;
        }
        
        i = n - 1, j = 0;
        while(i >= j) {
            maxAmount += prices[i];
            i--;
            j += k;
        }
        vector<int> ans;
        ans.push_back(minAmount);
        ans.push_back(maxAmount);
        return ans;
    }
};