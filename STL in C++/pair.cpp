#include<iostream>
// #include<pair>
#include<bits/stdc++.h>
using namespace std;

int main() {

    // pair<string,int> p;
    // p.first = "Rohit";
    // p.second = 30;
    // cout << p.first << " " << p.second << endl;

    pair<string,pair<int,int>> p;
    p.first = "Aman";
    p.second.first = 25;
    p.second.second = 75;
    cout << p.first << " " << p.second.first << " " << p.second.second << endl;
    return 0;
}