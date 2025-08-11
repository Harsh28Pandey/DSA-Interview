// Problem - Power of 2 (231) - LeetCode

#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}