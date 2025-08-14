# 🔗 Linked List in C++

This project demonstrates the concept and theory of **Linked Lists** in **C++**, covering all major types, operations, and important definitions essential for understanding how linked lists work as a data structure.

---

## 📘 What is a Linked List?

A **Linked List** is a linear data structure in which elements (called **nodes**) are stored in a sequence but are not stored in contiguous memory locations. Each node contains data and a reference (pointer) to the next node in the sequence.

Unlike arrays, linked lists allow efficient insertion and deletion of elements without reallocation or reorganization of the entire structure.

---

## 🧱 Basic Terminology

### 🔹 Node
The fundamental unit of a linked list. It contains two parts:
- **Data**: Stores the value or information.
- **Pointer (next)**: Points to the next node in the list.

### 🔹 Head
A pointer that refers to the **first node** in a linked list.

### 🔹 Tail
The **last node** in the list whose next pointer is usually `NULL` (or points back to the head in circular lists).

### 🔹 NULL
A special marker indicating the end of the list. If a node's next pointer is `NULL`, it’s the last node.

---

## 🧩 Types of Linked Lists

### 1. Singly Linked List
A list where each node contains a single pointer to the **next** node in the sequence. Traversal is unidirectional, from head to tail.

### 2. Doubly Linked List
Each node contains two pointers:
- One to the **next** node
- One to the **previous** node  
Allows traversal in **both directions** (forward and backward).

### 3. Circular Linked List
A variation of singly or doubly linked list where the **last node points back to the first node**, forming a circular loop. There is no `NULL` in the last node.

### 4. Circular Doubly Linked List
A **doubly linked list** in which the last node's next pointer points to the head, and the head’s previous pointer points to the tail.

---

## 🛠️ Fundamental Operations

### 🔸 Insertion
The process of adding a new node to the list. It can occur:
- At the beginning
- At the end
- At a specific position

### 🔸 Deletion
The process of removing a node from the list. It can be:
- From the beginning
- From the end
- From a specific position
- By value

### 🔸 Traversal
Visiting each node in the list one by one to perform operations like reading or modifying data.

### 🔸 Searching
Locating a node that contains a specific value by traversing through the list.

### 🔸 Updating
Changing the value stored in one or more nodes based on a condition or index.

### 🔸 Reversing
Changing the direction of the list by reversing the pointers in all nodes.

---

## 🧠 Advanced Concepts

### 🔹 Memory Management
Since nodes are dynamically allocated, proper memory management (using `delete` in C++) is essential to avoid memory leaks.

### 🔹 Time Complexity
- Insertion/Deletion at head: **O(1)**
- Insertion/Deletion at end (singly linked list): **O(n)**
- Search: **O(n)**
- Access by index: **O(n)**

### 🔹 Space Complexity
Requires extra memory for storing pointers in each node.

### 🔹 Sentinel Node
A dummy node used to simplify boundary conditions during insertion or deletion.

### 🔹 Circular vs Linear Lists
- **Linear**: The last node points to `NULL`
- **Circular**: The last node points to the head

### 🔹 Self-Referencing Structures
Each node has a pointer that refers to the same type (structure or class), enabling recursive structures.

---

## ⚙️ Use Cases of Linked Lists

- Dynamic memory allocation
- Implementing stacks, queues, and graphs
- Undo functionality in editors
- Music or image viewer (next/previous navigation)
- Real-time scheduling (round-robin algorithms)

---

## 🧾 Comparison with Arrays

| Feature            | Arrays             | Linked Lists        |
|--------------------|--------------------|---------------------|
| Memory Allocation  | Static             | Dynamic             |
| Insertion/Deletion | Costly (O(n))      | Efficient (O(1) or O(n)) |
| Random Access      | O(1)               | O(n)                |
| Memory Wastage     | Possible (fixed size) | Minimal (only when needed) |

---

## 📌 Summary

A linked list is a flexible and powerful data structure suited for dynamic data where frequent insertions and deletions are required. Mastering its types and operations forms the foundation for advanced data structures like stacks, queues, and graphs.

---

🎯 Whether you're preparing for coding interviews or just brushing up your skills, you'll find this repo helpful!

👉 Feel free to ⭐ star this repo, fork it, or contribute your own improvements!

---