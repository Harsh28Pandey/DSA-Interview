// Problem - Power of 4 (342) - LeetCode

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    // Keep dividing by 4 while divisible
    while (n % 4 == 0) {
    n /= 4;
    }
    return n == 1;
}