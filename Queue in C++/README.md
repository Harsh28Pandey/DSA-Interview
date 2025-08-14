# 📦 Queue in C++

This project provides a full conceptual overview of the **Queue** data structure in **C++**, including its definitions, operations, characteristics, types, use-cases, and related advanced topics. This README focuses entirely on **theoretical explanations** (no code included).

---

## 🧠 What is a Queue?

A **Queue** is a **linear data structure** that follows the **First In, First Out (FIFO)** principle. This means the **first element added** to the queue will be the **first one removed**.

It is analogous to a real-life queue, such as a line of people waiting — the person who joins first gets served first.

---

## 📘 Key Terminologies

| Term             | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| **Enqueue**      | The operation to **insert** an element at the **rear** of the queue.        |
| **Dequeue**      | The operation to **remove** an element from the **front** of the queue.     |
| **Front**        | The element at the beginning of the queue.                                  |
| **Rear (Back)**  | The element at the end of the queue.                                        |
| **FIFO**         | First-In, First-Out: the order in which elements are processed.             |
| **Underflow**    | An error condition when trying to dequeue from an empty queue.              |
| **Overflow**     | An error condition when trying to enqueue into a full queue (for fixed size).|

---

## 📦 Characteristics of a Queue

- **Linear structure**: Items are arranged sequentially.
- **FIFO ordering**: First inserted, first removed.
- **Fixed or dynamic size**: Implemented using arrays (static) or linked lists (dynamic).
- **Efficient**: Enqueue and Dequeue operations are O(1) in optimal implementations.

---

## 🔧 Basic Queue Operations

| Operation        | Description                                                                 |
|------------------|------------------------------------------------------------------------------|
| `enqueue(x)`     | Adds element `x` to the rear of the queue.                                  |
| `dequeue()`      | Removes and returns the front element of the queue.                         |
| `front()`        | Returns the front element without removing it.                              |
| `rear()`         | Returns the rear element without removing it.                               |
| `isEmpty()`      | Checks whether the queue is empty.                                           |
| `isFull()`       | Checks whether the queue is full (for fixed-size implementations).          |
| `size()`         | Returns the number of elements currently in the queue.                      |

---

## 🧩 Types of Queues

## 1. **Simple Queue (Linear Queue)**
- Standard FIFO queue.
- Elements are added at the rear and removed from the front.
- May lead to wasted space if not managed properly.

## 2. **Circular Queue**
- Treats the storage (usually an array) as circular.
- When rear reaches the end, it wraps around to the beginning.
- Prevents space wastage in fixed-size queues.

## 3. **Doubly Ended Queue (Deque)**
- Allows **insertion and deletion** from **both ends**.
- Can be used as both stack and queue.
- Two types:
  - **Input-restricted Deque**: Insert at one end, delete from both.
  - **Output-restricted Deque**: Delete at one end, insert from both.

## 4. **Priority Queue**
- Elements are assigned priorities.
- Higher priority elements are dequeued before lower ones, regardless of insertion order.
- Can be implemented using heaps or custom comparators.

## 5. **Double-Ended Priority Queue**
- A combination of deque and priority queue.
- Supports quick access to both minimum and maximum elements.

---

## 🧠 Queue vs Stack

| Feature            | Queue (FIFO)         | Stack (LIFO)        |
|--------------------|----------------------|---------------------|
| Insertion Point    | Rear                 | Top                 |
| Removal Point      | Front                | Top                 |
| Access Order       | First In, First Out  | Last In, First Out  |
| Common Use Cases   | Scheduling, Buffers  | Undo/Redo, Recursion|

---

## 🧪 Applications of Queue

Queues are widely used in both system-level and application-level programming:

- **CPU scheduling** (Round-robin, FCFS)
- **I/O Buffer management**
- **Print job management**
- **Breadth-First Search (BFS)** in trees and graphs
- **Data streaming** and **real-time processing**
- **Simulation systems**
- **Handling requests in web servers**
- **Message queues** in distributed systems

---

## 🧠 Queue in C++ STL

C++ provides a built-in **`queue`** container adaptor in the Standard Template Library (STL), which operates over `deque` by default.

It supports all standard queue operations:
- `push()` → enqueue
- `pop()` → dequeue
- `front()` → access front
- `back()` → access rear
- `empty()` → check if empty
- `size()` → number of elements

Also available:
- `std::deque` (double-ended queue)
- `std::priority_queue` (for prioritized elements)

---

## 📚 Further Topics to Explore

## 🔹 Queue using Linked List
A dynamic implementation that avoids overflow and allows unlimited size (as long as memory is available).

## 🔹 Queue using Two Stacks
Implements a queue using two stacks to reverse the order of elements during enqueue or dequeue.

## 🔹 Multi-Level Queues
Used in CPU scheduling to manage processes of different priority levels in separate queues.

## 🔹 Thread-safe Queues
Queues implemented with synchronization (mutexes/locks) for concurrent environments.

## 🔹 Blocking Queues
Queues that pause producers or consumers when the queue is full or empty, respectively — used in multithreaded systems.

---

## 📝 Summary

A **queue** is an essential linear data structure for managing data in a **first-come-first-served** manner. It plays a critical role in algorithm design, process scheduling, streaming data, and more. C++ supports queues through both custom implementations and powerful STL abstractions.

---

⭐ If you find this helpful, consider giving it a star!

---