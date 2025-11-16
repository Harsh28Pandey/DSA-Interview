#include<iostream>
#include<vector>
using namespace std;

// undirected-unweighted graph

int main() {
    int vertex, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edges;

    vector<int> adjList[vertex];
    int u,v;

    for(int i = 0; i < edges; i++) {
        cout << "Enter edge: ";
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // print the list
    for(int i = 0; i < vertex; i++) {
        cout << i << "-> ";
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}