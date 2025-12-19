#include<iostream>
// #include<list>
#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;
    l.push_back(30);
    l.push_back(20);
    l.push_back(40);
    l.push_back(10);
    l.push_front(80);

    l.pop_back();

    cout << l.front() << " " << l.back() << endl;
    cout << l.size() << endl;

    // it = iterator

    // print the list
    cout << "List: ";
    for(auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // print the reverse list
    cout << "Reverse List: ";
    for(auto it = l.rbegin(); it != l.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}