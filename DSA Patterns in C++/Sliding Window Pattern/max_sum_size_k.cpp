// Problem - Max Sum of Size K - GeeksForGeeks
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = 0;
        int maxValue = 0;
        
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        maxValue = max(maxValue,sum);
        
        for(int i = k; i < arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];
            
            maxValue = max(maxValue,sum);
        }
        
        return maxValue;
    }
};