#include<iostream>
#include<vector>
using namespace std;

// directed-weighted graph

int main() {
    int vertex, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edges;

    vector<vector<int>> adjMatrix(vertex,vector<int> (vertex,0));
    int u,v,weight;

    for(int i = 0; i < edges; i++) {
        cout << "Enter edge: ";
        cin >> u >> v >> weight;
        adjMatrix[u][v] = weight;
    }

    // print the matrix
    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}