// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(int vertex, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    visited[vertex] = true;
    q.push({vertex, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true; // Cycle detected
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (BFS(i, adj, visited)) {
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