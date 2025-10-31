#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,310));
    m.insert(make_pair(40,230));
    m.insert(make_pair(20,230));
    m.insert(make_pair(50,30));
    // m[100] = 60; // this is also allowed
    // m.erase(20); // delete

    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}