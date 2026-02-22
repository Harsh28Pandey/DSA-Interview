// Problem - Binary Gap (868) - LeetCode
// Time Complexity - O(log n)
// Space Complexity - O(1)

class Solution {
public:
    int binaryGap(int n) {
        int currPos = 0;
        int lastPos = -1;
        int maxDistance = 0;

        while(n > 0) {
            int rem = n % 2;
            if(rem == 1) {
                if(lastPos != -1) {
                    maxDistance = max(maxDistance,currPos - lastPos);
                }
                lastPos = currPos;
            }
            n /= 2;
            currPos++;
        }
        return maxDistance;
    }
};