// Problem - Prime Number of Set Bits in Binary Representation (762) - LeetCode
// Time Complexity - R * Sqrt(log R)
// Space Complexity - O(1)

class Solution {
public:
    int countBits(int n) {
        int bits = 0;
        while(n > 0) {
            if(n % 2 == 1) {
                bits++;
            }
            n /= 2;
        }
        return bits;
    }

    bool isPrime(int n) {
        if(n < 2) {
            return false;
        }
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++) {
            int setBits = countBits(i);

            if(isPrime(setBits)) {
                count++;
            }
        }
        return count;
    }
};