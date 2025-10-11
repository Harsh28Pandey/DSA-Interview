// Time Complexity - O(V + E)
// where V - Vertex and E - Edges

#include<iostream>
#include<vector>
#include<list>
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

    bool isCycleUndirectedDFS(int src, int parent, vector<bool> &visited) { // dfs algorithm
        visited[src] = true;
        list<int> neighbour = l[src];
        for(int v : neighbour) {
            if(!visited[v]) {
                if(isCycleUndirectedDFS(v,src,visited)) {
                    return true;
                }
            }
            else if(v != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle() {
        vector<bool> visited(V,false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(isCycleUndirectedDFS(i,-1,visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    // 1 - cycle detected and 0 - cycle not detected
    cout << g.isCycle() << endl;
    return 0;
}