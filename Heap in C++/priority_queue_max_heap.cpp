#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> p;

    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    cout << p.top() << " " << endl;
    
    // delete
    p.pop();

    cout << p.top() << " " << endl;

    // size
    cout << p.size() << " " << endl;

    while(!p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
    return 0;
}