# 🔁 Doubly Linked List in C++

This project provides a theoretical understanding of the **Doubly Linked List** data structure in C++. It covers all key types, definitions, and advanced concepts related to doubly linked lists, which are essential in various real-world applications and complex data handling tasks.

---

## 🧾 What is a Doubly Linked List?

A **Doubly Linked List (DLL)** is a type of linked list in which each node contains three components:
- **Data**: The value stored in the node.
- **Next pointer**: Points to the **next** node in the list.
- **Previous pointer**: Points to the **previous** node in the list.

This bi-directional linking allows traversal of the list in **both forward and backward** directions.

---

## 🔍 Key Definitions

## 🔹 Node
The fundamental unit of a doubly linked list. Each node consists of:
- A data field
- A pointer to the next node
- A pointer to the previous node

## 🔹 Head
A pointer that references the **first node** of the list.

## 🔹 Tail
A pointer that references the **last node** of the list.

## 🔹 NULL
A special constant that indicates the **end** of the list. The previous pointer of the head and the next pointer of the tail usually point to `NULL`.

---

## 🧱 Types of Doubly Linked Lists

## 1. **Linear Doubly Linked List**
A standard doubly linked list where:
- The first node’s previous pointer is `NULL`.
- The last node’s next pointer is `NULL`.

## 2. **Circular Doubly Linked List**
A variation in which:
- The first node’s previous pointer points to the last node.
- The last node’s next pointer points to the first node.
This structure creates a circular loop and eliminates `NULL` pointers.

---

## 🔧 Fundamental Operations

## 🔸 Insertion
The process of adding a new node to the list. It can occur:
- At the beginning (before head)
- At the end (after tail)
- At a specific position (based on index or value)

## 🔸 Deletion
The process of removing a node from the list. It can be:
- From the beginning
- From the end
- From a specific position or by value

## 🔸 Traversal (Forward and Backward)
Navigating the list from head to tail (forward) or tail to head (backward) using the next and previous pointers.

## 🔸 Search
Finding a node containing a specified value by traversing the list in either direction.

## 🔸 Update
Modifying the data field of one or more nodes based on a specific condition or index.

## 🔸 Reversal
Reversing the order of nodes by swapping the next and previous pointers of each node.

---

## 🧠 Advanced Concepts

## 🔹 Bidirectional Traversal
The ability to traverse both forward and backward enhances flexibility and is particularly useful in navigation systems, undo-redo functionalities, etc.

## 🔹 Memory Overhead
Each node requires **extra memory** for the additional pointer (`prev`), compared to a singly linked list.

## 🔹 Doubly Circular List vs Linear DLL
- A **linear DLL** ends with `NULL`.
- A **circular DLL** connects tail to head and vice versa, allowing infinite circular traversal.

## 🔹 Sentinel/Dummy Nodes
Special nodes used at the beginning and end of the list to **simplify edge cases** (e.g., insert/delete operations at boundaries).

## 🔹 Iterator Design
Doubly linked lists are suitable for creating **iterators** in data structures like stacks, queues, and custom containers.

### 🔹 Time Complexity (for DLL)
| Operation         | Time Complexity |
|------------------|-----------------|
| Insertion (begin) | O(1)           |
| Insertion (end)   | O(1)           |
| Deletion (begin)  | O(1)           |
| Deletion (end)    | O(1)           |
| Traversal/Search  | O(n)           |

### 🔹 Space Complexity
Due to the additional pointer in each node, DLLs have a **higher space complexity** than singly linked lists.

---

## 📌 Advantages of Doubly Linked Lists

- **Bi-directional traversal**
- **Efficient insertions and deletions** at both ends
- **Backtracking capability**
- Ideal for **complex data structures** like Deques, Navigators, and Undo-Redo systems

---

## ⚠️ Limitations

- **Increased memory usage** due to the extra pointer
- **Slightly more complex implementation**
- **More pointer management**, increasing the chance of errors (e.g., broken links)

---

## 🧪 Applications

- Browser history navigation (forward/backward)
- Undo/Redo operations in text editors
- Playlist navigation
- Implementation of complex data structures like:
  - Deques (Double-ended queues)
  - Fibonacci heaps
  - Navigation in file systems

---

## 📝 Summary

A **Doubly Linked List** is a powerful, flexible data structure that allows efficient two-way traversal, insertions, and deletions. Despite a higher memory cost compared to singly linked lists, DLLs are widely used in systems that require dynamic data handling and bidirectional operations.

---

🎯 Whether you're preparing for coding interviews or just brushing up your skills, you'll find this repo helpful!

👉 Feel free to ⭐ star this repo, fork it, or contribute your own improvements!

---