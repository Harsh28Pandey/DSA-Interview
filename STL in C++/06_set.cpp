#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    // set<int> s; // ascending order
    set<int, greater<int>> s; // descending order
    s.insert(10);
    s.insert(20);
    s.insert(110);
    s.insert(200);
    s.insert(10);
    s.insert(20);

    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }

    // search
    // if(s.find(200) != s.end) {
    //     cout << "Present";
    // }
    // else {
    //     cout << "Absent";
    // }

    // delete
    // s.erase(110);

    return 0;
}