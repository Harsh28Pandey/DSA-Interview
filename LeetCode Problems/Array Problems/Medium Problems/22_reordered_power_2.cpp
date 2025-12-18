// Problem - Reordered Power of 2 (869) - LeetCode

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool reorderedPowerOf2(int n) {
    string s = to_string(n);
    sort(s.begin(),s.end());
    for(int i = 0; i < 31; i++) {
        string t = to_string(1 << i);
        sort(t.begin(),t.end());
        if(s == t) 
            return true;
    } 
    return false;
}

int main() {
    int n = 16; // Example input
    if(reorderedPowerOf2(n)) {
        cout << n << " can be reordered to form a power of 2." << endl;
    } else {
        cout << n << " cannot be reordered to form a power of 2." << endl;
    }
    return 0;
}