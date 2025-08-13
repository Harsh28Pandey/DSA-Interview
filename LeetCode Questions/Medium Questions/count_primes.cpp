// Problem - Count Primes (204) - LeetCode

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    int count = 0;
    for(int i = 2; i < n; i++) {
        if(isPrime[i]) {
            count++;
            for(int j = i * 2; j < n; j = j + i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }
    return count;
}

int main() {
    int n = 10;
    cout << "Number of primes less than " << n << ": " << countPrimes(n) << endl; // Output: 4
    return 0;
}