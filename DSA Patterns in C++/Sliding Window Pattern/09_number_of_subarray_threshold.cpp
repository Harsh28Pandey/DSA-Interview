// Problem - Number of Subarrays of Size K and Average Greater than or Equal to Threshold (1343) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int maxThreshold = k * threshold;

        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int count = 0;
        if(sum >= maxThreshold) {
            count++;
        }

        for(int i = k; i < arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];

            if(sum >= maxThreshold) {
                count++;
            }
        }
        return count;
    }
};