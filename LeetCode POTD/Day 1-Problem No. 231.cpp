// Problem - Power of 2 (231) - LeetCode

bool isPowerOfTwo(int n) {
    if(n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}