// Problem - Count Number of Hops - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)


class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int ways(int n, vector<int> &dp) {
        if(n <= 1)
        return 1;
        
        if(n == 2)
        return 2;
        
        if(dp[n] != -1)
        return dp[n];
        
        return dp[n] = (ways(n - 1,dp) + ways(n - 2,dp) + ways(n - 3,dp)) % 1000000007;
    }
    
    int countWays(int n) {

        // your code here
        vector<int> dp(n + 1,-1);
        return ways(n,dp);
    }
};
