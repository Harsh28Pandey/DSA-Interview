# 📚 Stack in C++

This project provides a complete theoretical overview of the **Stack** data structure in **C++**, covering fundamental concepts, operations, types, applications, and implementation strategies — explained in detail without code.

---

## 🧠 What is a Stack?

A **Stack** is a **linear data structure** that follows the **Last In, First Out (LIFO)** principle. This means the **last element added (pushed)** onto the stack is the **first one to be removed (popped)**.

Think of a stack like a pile of books — you can only take the top book off (pop) or place another book on the top (push).

---

## 📘 Key Terminology

| Term         | Definition                                                                 |
|--------------|-----------------------------------------------------------------------------|
| **Push**     | Operation to insert (add) an element onto the top of the stack.            |
| **Pop**      | Operation to remove the topmost element from the stack.                    |
| **Top / Peek** | Operation to view the element at the top of the stack without removing it. |
| **Underflow**| Error that occurs when trying to pop from an empty stack.                  |
| **Overflow** | Error that occurs when trying to push into a full stack (for fixed-size stacks). |
| **LIFO**     | Last-In, First-Out; describes the access order in a stack.                 |

---

## 🧱 Characteristics of Stack

- **Linear**: Elements are arranged sequentially.
- **Restricted Access**: Only the top element can be accessed or modified directly.
- **Dynamic or Static**: Stacks can be implemented using either dynamic (linked list) or static (array) memory.
- **Efficient**: Both push and pop operations are performed in **constant time O(1)**.

---

## 🧩 Types of Stacks

## 🔸 1. Array-Based Stack
- Uses a fixed-size array.
- Simple to implement.
- May cause **overflow** if the array is full.

## 🔸 2. Linked List-Based Stack
- Uses dynamic memory with nodes.
- Grows and shrinks as needed.
- No overflow (unless memory is exhausted).

---

## 🔧 Fundamental Operations

| Operation | Description                                                                 |
|-----------|-----------------------------------------------------------------------------|
| **push(x)** | Adds element `x` to the top of the stack.                                 |
| **pop()**   | Removes and returns the top element of the stack.                         |
| **top()** / **peek()** | Returns the top element without removing it.                   |
| **isEmpty()** | Checks if the stack contains no elements.                               |
| **isFull()** | Checks if the stack is full (for array implementation).                  |
| **size()**   | Returns the number of elements in the stack.                             |

All basic operations in a stack typically have a **time complexity of O(1)**.

---

## 🧠 Stack vs Other Data Structures

| Feature          | Stack             | Queue             | Array             |
|------------------|-------------------|-------------------|-------------------|
| Insertion Order  | LIFO              | FIFO              | Random Access     |
| Insertion Point  | Top               | Rear              | Any index         |
| Deletion Point   | Top               | Front             | Any index         |
| Access           | Top-only          | Front-only        | Any index         |

---

## 🧪 Applications of Stack

Stacks are widely used in many computer science areas, including:

- **Function Call Management**: The call stack stores function return addresses.
- **Expression Evaluation**:
  - Infix to Postfix/Prefix conversion
  - Postfix expression evaluation
- **Undo/Redo Functionality**: Used in text editors, image editors, etc.
- **Syntax Parsing**: Compilers use stacks to match brackets, parse expressions, etc.
- **Backtracking Algorithms**: Like solving mazes, Sudoku, and DFS in graphs.
- **Reversing Data**: Reverse a string, linked list, etc.
- **Memory Management**: Stack memory stores local variables and function calls.

---

## 🧠 Advanced Stack Concepts

## 🔹 Stack Frame
A structure that stores information about a function call (e.g., return address, local variables) in the call stack.

## 🔹 Recursion and Stack
Each recursive function call creates a new stack frame, managed by the system’s call stack. Deep recursion can lead to stack overflow.

## 🔹 Stack Overflow
Occurs when the system’s call stack limit is exceeded — typically due to infinite or very deep recursion.

---

## ⚙️ Stack in C++ STL

C++ provides a built-in **`stack`** container adaptor in the Standard Template Library (STL), built over a **deque** by default. It supports all standard stack operations.

Operations available:
- `push()`
- `pop()`
- `top()`
- `empty()`
- `size()`

---

## 📚 Further Topics to Explore

## 1. Stack Implementation Using Linked List
Instead of using a static array, a stack can be implemented using a **linked list** where:
- Each node holds a value and a pointer to the next node.
- The top of the stack corresponds to the head of the linked list.
- Dynamic memory allocation eliminates fixed size limitations.
- Push and pop operations take O(1) time.

---

## 2. Stack Using Two Queues
A stack can be simulated using two queues by reversing the order of elements during **push** or **pop** to maintain the **LIFO** behavior.
- Two strategies:
  - **Costly push**: Rearranging elements during insertion.
  - **Costly pop**: Moving elements to another queue during removal.
- Useful for understanding differences between FIFO (queue) and LIFO (stack).

---

## 3. Expression Tree Using Stack
An **expression tree** represents arithmetic expressions in a tree format:
- Operands become leaf nodes.
- Operators become internal nodes.
- Postfix expressions can be used to construct the tree using a stack.
- Useful in compilers and calculators to parse and evaluate expressions efficiently.

---

## 4. Min/Max Stack (Track Min/Max in O(1))
A specialized stack that supports:
- `push(x)`
- `pop()`
- `getMin()` or `getMax()` → returns the minimum or maximum element **in O(1)** time.
- Achieved by maintaining an auxiliary stack that keeps track of the current min/max values alongside the main stack.

---

## 5. Stack with Limited Memory
In systems with constrained memory (e.g., embedded systems), stack implementations must:
- Prevent overflow and underflow errors.
- Avoid dynamic memory allocation.
- Use fixed-size arrays or circular buffers.
- Often designed with boundary checks and optimization techniques for minimal space usage.

---

## 6. Browser Forward/Backward Navigation Using Stacks
Web browsers use **two stacks** to implement navigation:
- **Back Stack**: Stores previously visited pages.
- **Forward Stack**: Stores pages visited after pressing the back button.
- Navigating:
  - **Back**: Pop from back stack, push to forward stack.
  - **Forward**: Pop from forward stack, push to back stack.

---

## 7. Stack-Based Sorting Algorithms
Sorting a stack using only another stack and standard stack operations (no arrays or recursion). Common approaches:
- **Sort Stack Using Recursion**: Insert elements in sorted order using recursive calls.
- **Sort Stack Using Auxiliary Stack**: Use a second stack to insert elements in the correct position by comparison.
- These algorithms demonstrate stack manipulation skills under constraints.

---


## 📝 Summary

A **stack** is a foundational linear data structure that offers efficient LIFO access to data. It’s simple yet incredibly powerful, used internally by systems and in a variety of programming problems.

Mastering stack operations and understanding their usage in both system-level and algorithmic contexts is crucial for any developer or computer science student.

---

⭐ If you find this helpful, consider giving it a star!

---