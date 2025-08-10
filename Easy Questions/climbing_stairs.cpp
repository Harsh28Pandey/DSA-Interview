// Problem - Climbing Stairs (70) - LeetCode

#include<iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;  // Base cases: n=1 → 1 way, n=2 → 2 ways

    int first = 1;  // ways to reach step 1
    int second = 2; // ways to reach step 2

    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }

    return second;
}

int main() {
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}