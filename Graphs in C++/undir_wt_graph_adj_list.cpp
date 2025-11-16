#include<iostream>
#include<vector>
using namespace std;

// undirected-weighted graph

int main() {
    int vertex, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edges;

    vector<pair<int,int>> adjList[vertex];
    int u,v,weight;

    for(int i = 0; i < edges; i++) {
        cout << "Enter edge: ";
        cin >> u >> v;
        adjList[u].push_back(make_pair(v,weight));
        adjList[v].push_back(make_pair(u,weight));
    }

    // print the list
    for(int i = 0; i < vertex; i++) {
        cout << i << "-> ";
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j].first << " " << adjList[i][j].second << " ";
        }
        cout << endl;
    }
    return 0;
}