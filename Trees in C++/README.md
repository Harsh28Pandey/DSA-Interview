# 🌳 Trees in C++

This project provides a complete theoretical overview of the **Tree** data structure in C++. It covers fundamental definitions, types of trees, important properties, and key concepts related to trees, essential for understanding hierarchical data organization and algorithms.

---

## 🧠 What is a Tree?

A **Tree** is a non-linear, hierarchical data structure composed of nodes connected by edges, with the following characteristics:

- It has a single **root node** from which all nodes descend.
- Each node contains **data** and zero or more **child nodes**.
- There are **no cycles** in a tree (i.e., there is exactly one path between any two nodes).
- A tree with *n* nodes has exactly *n-1* edges.

---

## 📘 Key Terminologies

| Term               | Definition                                                                                      |
|--------------------|------------------------------------------------------------------------------------------------|
| **Node**           | The basic unit of a tree containing data and pointers/references to child nodes.                |
| **Root**           | The topmost node of a tree with no parent.                                                     |
| **Parent**         | A node that has one or more child nodes.                                                       |
| **Child**          | A node directly connected to another node when moving away from the root.                      |
| **Leaf (External Node)** | A node with no children.                                                                   |
| **Internal Node**  | A node with at least one child.                                                                |
| **Edge**           | The connection between a parent node and a child node.                                        |
| **Subtree**        | A tree consisting of a node and all its descendants.                                           |
| **Degree of a Node** | The number of children a node has.                                                           |
| **Height of a Node** | The number of edges on the longest downward path between that node and a leaf.                |
| **Depth of a Node** | The number of edges from the root to the node.                                                 |
| **Height of a Tree** | The height of the root node; maximum depth among all nodes.                                   |
| **Level**          | Nodes at the same depth belong to the same level.                                              |

---

## 🧩 Types of Trees

## 1. **General Tree**
A tree in which each node can have an arbitrary number of children.

## 2. **Binary Tree**
A tree in which each node has **at most two children**, typically referred to as:
- **Left child**
- **Right child**

## 3. **Full Binary Tree**
A binary tree in which every node has either **0 or 2 children** (no nodes have only one child).

## 4. **Complete Binary Tree**
A binary tree in which **all levels are completely filled except possibly the last**, which is filled from left to right.

## 5. **Perfect Binary Tree**
A binary tree that is both **full and complete** — all internal nodes have two children and all leaf nodes are at the same level.

## 6. **Balanced Binary Tree**
A binary tree where the **height difference between left and right subtrees** of every node is at most one.

## 7. **Binary Search Tree (BST)**
A binary tree where:
- Left subtree of a node contains only nodes with keys **less than** the node’s key.
- Right subtree contains only nodes with keys **greater than** the node’s key.
- Both subtrees are also BSTs.

## 8. **AVL Tree**
A **self-balancing BST** where the difference between heights of left and right subtrees is at most 1 for all nodes.

## 9. **Red-Black Tree**
A self-balancing BST with additional color properties to maintain approximately balanced height during insertions and deletions.

## 10. **N-ary Tree**
A generalization of binary trees where each node can have up to *N* children.

## 11. **Trie (Prefix Tree)**
A tree used to store associative data structures such as dictionaries; nodes represent prefixes of strings.

---

## 🔧 Basic Operations on Trees

## 🔸 Traversal
Visiting all nodes in a tree in a specific order:

- **Preorder** (Root → Left → Right)
- **Inorder** (Left → Root → Right)
- **Postorder** (Left → Right → Root)
- **Level-order** (Breadth-First traversal, visiting nodes level by level)

## 🔸 Insertion
Adding a new node to the tree following specific rules depending on the tree type (e.g., BST insertion places node according to key value).

## 🔸 Deletion
Removing a node and reorganizing the tree to maintain its properties.

## 🔸 Searching
Finding a node with a given value or key.

---

## 🧠 Important Properties

- A tree with *n* nodes has exactly *n-1* edges.
- The maximum number of nodes at level *l* is \( 2^l \) in a binary tree.
- The maximum number of nodes in a binary tree of height *h* is \( 2^{h+1} - 1 \).
- In a full binary tree, the number of leaf nodes is one more than the number of internal nodes.
- Balanced trees guarantee \( O(\log n) \) time for search, insertion, and deletion.

---

## 🌳 Specialized Trees and Their Uses

- **Binary Search Trees** are used for efficient searching and sorting.
- **AVL and Red-Black Trees** provide balanced trees to maintain performance guarantees.
- **Trie** is widely used in autocomplete and spell-check features.
- **Segment Trees** and **Fenwick Trees (Binary Indexed Trees)** support efficient range queries and updates.
- **Heap Trees** (Binary Heaps) implement priority queues.

---

## 📚 Further Topics to Explore

## 1. Tree Rotations (used in AVL and Red-Black Trees)
Tree rotations are operations that change the structure of a binary tree without affecting the **in-order traversal sequence**. They are used to **rebalance** trees after insertions or deletions.

- **Left Rotation**: Moves a node down to the left, and its right child up to take its place.
- **Right Rotation**: Moves a node down to the right, and its left child up to take its place.

These rotations help maintain balance in self-balancing trees like AVL and Red-Black trees, ensuring efficient search times.

---

## 2. Balanced Tree Algorithms (AVL, Red-Black)
Balanced trees automatically maintain their height to be logarithmic relative to the number of nodes, optimizing search, insertion, and deletion operations.

- **AVL Tree**: Ensures the heights of left and right subtrees differ by at most one for every node. Uses rotations to restore balance.
- **Red-Black Tree**: A binary search tree with an extra color property (red or black) for each node, which enforces balanced paths and reduces the frequency of rotations compared to AVL trees.

---

## 3. Segment Trees and Fenwick Trees

- **Segment Tree**: A tree data structure used for storing information about intervals or segments. It allows efficient querying and updating of range-based data (like sums, minimums, maximums) in logarithmic time.
  
- **Fenwick Tree (Binary Indexed Tree)**: A space-efficient data structure that supports prefix sums and updates in logarithmic time. Simpler to implement but less versatile than segment trees.

Both are extensively used in range query problems and competitive programming.

---

## 4. Trie Variants and Applications

A **Trie** (prefix tree) stores keys, usually strings, by breaking them down into characters along paths from the root.

- Variants include **compressed tries**, **suffix tries**, and **ternary search tries**.
- Applications:
  - Auto-complete and spell checking
  - IP routing
  - Searching for patterns in texts

---

## 5. Tree Traversal Iterative Implementations

While recursive traversal is intuitive, **iterative traversal** uses explicit stacks or queues to avoid recursion overhead and handle larger trees efficiently.

- Iterative **inorder**, **preorder**, and **postorder** traversals use stacks.
- Iterative **level-order** traversal uses a queue.

Iterative methods are crucial for environments where recursion depth is limited.

---

## 6. Expression Trees and Parse Trees

- **Expression Tree**: A binary tree used to represent arithmetic expressions where internal nodes are operators and leaves are operands.
  
- **Parse Tree**: A tree representing the syntactic structure of a string according to a grammar (commonly used in compilers).

These trees help in evaluating expressions, compiling code, and processing structured data.

---

## 7. Binary Heap and Priority Queues

- **Binary Heap**: A complete binary tree that satisfies the heap property:
  - **Max-Heap**: Parent nodes are greater than or equal to their children.
  - **Min-Heap**: Parent nodes are less than or equal to their children.

- **Priority Queue**: An abstract data type often implemented using binary heaps to efficiently manage a dynamically changing set where each element has a priority.

Heaps enable efficient retrieval of the highest or lowest priority element, used in algorithms like Dijkstra’s shortest path and scheduling.

---

## 📝 Summary

Trees are versatile and foundational data structures essential for representing hierarchical relationships, enabling fast data access, insertion, and deletion. Understanding different types of trees and their properties allows choosing the best structure for specific problems.

---

⭐ If you find this helpful, consider giving it a star!

---
