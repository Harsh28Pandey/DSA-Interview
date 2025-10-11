// Time Complexity - O(V + E)
// where V - Vertex and E - Edges

#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;
    public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V]; // arr = new int[V]
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfsTraversal() {
        queue<int> q;
        vector<bool> visited(V,false);
        q.push(0);
        visited[0] = true;
        while(q.size() > 0) {
            int u = q.front(); // u - v
            q.pop();
            cout << u << " ";
            for(int v : l[u]) { // v - immediate neighbour of u
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.bfsTraversal();
    return 0;
}