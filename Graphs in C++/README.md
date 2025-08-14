# 🌐 Graphs in C++

This project provides a comprehensive overview of the **Graph** data structure in **C++**, covering all major types, terminologies, representations, and algorithms — with theoretical definitions only.

---

## 🧠 What is a Graph?

A **Graph** is a non-linear data structure that consists of:
- A set of **vertices** (also called **nodes** or **points**)
- A set of **edges** (also called **arcs** or **links**) that connect pairs of vertices.

Formally, a graph is represented as:
Where:
- `V` is the set of vertices
- `E` is the set of edges (pairs of vertices)

Graphs are used to model real-world systems such as networks, maps, social connections, and more.

---

## 📘 Key Terminologies

| Term | Definition |
|------|------------|
| **Vertex (Node)** | A fundamental unit or point in the graph. |
| **Edge (Arc)** | A connection between two vertices. |
| **Adjacency** | Two vertices are adjacent if they are connected by an edge. |
| **Degree** | The number of edges incident to a vertex. |
| **Path** | A sequence of vertices connected by edges. |
| **Cycle** | A path that starts and ends at the same vertex without repeating edges or nodes. |
| **Connected Graph** | A graph where there is a path between every pair of vertices. |
| **Component** | A disconnected subgraph where all vertices are connected within, but not to others outside. |
| **Weighted Edge** | An edge with an associated numerical value or cost. |
| **Unweighted Edge** | An edge without any weight or cost. |
| **Directed Edge** | An edge with a direction (from one vertex to another). |
| **Undirected Edge** | An edge with no direction (bidirectional). |

---

## 🔗 Types of Graphs

## 🔸 1. **Undirected Graph**
A graph where all edges are bidirectional. If there is an edge between A and B, you can travel both from A to B and from B to A.

## 🔸 2. **Directed Graph (Digraph)**
A graph where edges have a direction. If there is an edge from A to B, it does not imply an edge from B to A.

## 🔸 3. **Weighted Graph**
A graph in which each edge has an associated weight or cost, often representing distance, time, or capacity.

## 🔸 4. **Unweighted Graph**
A graph in which edges do not carry any weights.

## 🔸 5. **Cyclic Graph**
A graph containing at least one cycle (a path that starts and ends at the same node).

## 🔸 6. **Acyclic Graph**
A graph with no cycles. If directed and acyclic, it's referred to as a **Directed Acyclic Graph (DAG)**.

## 🔸 7. **Connected Graph**
In an undirected graph, if there is a path between every pair of vertices, the graph is considered connected.

## 🔸 8. **Disconnected Graph**
A graph in which at least one pair of vertices has no path connecting them.

## 🔸 9. **Complete Graph**
A graph where there is a direct edge between every pair of vertices.

## 🔸 10. **Sparse Graph**
A graph with relatively few edges compared to the number of vertices.

## 🔸 11. **Dense Graph**
A graph with a large number of edges, close to the maximum possible number.

## 🔸 12. **Multigraph**
A graph that may have multiple edges between the same pair of vertices.

## 🔸 13. **Null Graph**
A graph with no edges, only vertices.

---

## 🧩 Graph Representations in C++

Graphs can be represented in memory using different structures:

## 🔹 1. **Adjacency Matrix**
A 2D array where each cell `(i, j)` indicates whether there is an edge from vertex `i` to vertex `j`.

- Easy to implement.
- Efficient for dense graphs.
- High space complexity: O(V²)

## 🔹 2. **Adjacency List**
An array or map where each element stores a list of connected vertices.

- Space efficient for sparse graphs.
- Efficient for iterating over neighbors.
- Preferred in most use cases.

## 🔹 3. **Edge List**
A list of all edges stored as pairs or triplets (for weighted graphs).

- Good for certain algorithms like Kruskal’s.

---

## 🧠 Core Graph Concepts

## 🔸 Graph Traversal
The process of visiting all the nodes in a graph.

- **Breadth-First Search (BFS)**: Explores neighbors level by level.
- **Depth-First Search (DFS)**: Explores as far as possible along each branch before backtracking.

## 🔸 Connectivity
Determines whether the graph is fully connected or not.

## 🔸 Strongly Connected Component (SCC)
In a directed graph, a strongly connected component is a subset of vertices where each vertex is reachable from every other vertex in the subset.

## 🔸 Topological Sorting
A linear ordering of vertices such that for every directed edge `u → v`, `u` comes before `v`. Applicable only in DAGs.

## 🔸 Shortest Path
Finding the minimum path between two nodes:
- **Dijkstra’s Algorithm**: For weighted graphs with non-negative weights.
- **Bellman-Ford Algorithm**: Handles negative weights.
- **Floyd-Warshall Algorithm**: For all-pairs shortest path.

## 🔸 Minimum Spanning Tree (MST)
A subgraph that connects all vertices with the minimum total edge weight, with no cycles.
- **Kruskal’s Algorithm**
- **Prim’s Algorithm**

## 🔸 Cycle Detection
Determines whether the graph contains a cycle.
- DFS-based methods for both directed and undirected graphs.

## 🔸 Bipartite Graph
A graph whose vertices can be divided into two sets such that no two nodes in the same set are adjacent.

---

## 🧮 Time and Space Complexity Overview

| Operation               | Adjacency Matrix | Adjacency List |
|------------------------|------------------|----------------|
| Add edge               | O(1)             | O(1)           |
| Remove edge            | O(1)             | O(k)           |
| Check if edge exists   | O(1)             | O(k)           |
| Enumerate neighbors    | O(V)             | O(k)           |
| Space complexity       | O(V²)            | O(V + E)       |

---

## 🔧 Common Algorithms on Graphs

| Algorithm             | Purpose                        |
|-----------------------|--------------------------------|
| BFS                   | Level-order traversal          |
| DFS                   | Path exploration & cycle check |
| Dijkstra              | Single-source shortest path    |
| Bellman-Ford          | Shortest path (with negatives) |
| Floyd-Warshall        | All-pairs shortest paths       |
| Kruskal               | Minimum Spanning Tree          |
| Prim                  | Minimum Spanning Tree          |
| Tarjan’s Algorithm    | Strongly Connected Components  |
| Kahn’s Algorithm      | Topological Sort (BFS-based)   |

---

## 🧪 Applications of Graphs

- Social networks (friends, followers)
- Maps and GPS navigation
- Network routing (data packets, internet)
- Task scheduling (DAGs)
- Game maps and AI pathfinding
- Web page link structures (search engines)
- Electrical circuits
- Course prerequisites (Topological Sort)

---

## 📝 Summary

Graphs are one of the most powerful and flexible data structures in computer science. Mastering graph theory concepts and algorithms is essential for solving real-world and competitive programming problems involving networks, relationships, and dynamic systems.

---

## 📚 Further Topics to Explore

- Disjoint Set Union (DSU) / Union-Find
- Network Flow Algorithms (Ford-Fulkerson)
- Eulerian and Hamiltonian paths
- Bridge and Articulation Points
- Graph Coloring
- Dynamic Connectivity
- Planar Graphs

---

⭐ If you find this helpful, consider giving it a star!

---