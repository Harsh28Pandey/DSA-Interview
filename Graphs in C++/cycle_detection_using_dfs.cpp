// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
using namespace std;

bool detectCycleDFS(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (detectCycleDFS(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detectCycleDFS(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<int> adj[V];

    // Example graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1); // This edge creates a cycle

    if (isCycle(V, adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}