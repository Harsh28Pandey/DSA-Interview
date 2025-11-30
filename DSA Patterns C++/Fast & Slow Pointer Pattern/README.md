# ⚡ Fast & Slow Pointer Pattern in C++

The **Fast & Slow Pointer Technique (Tortoise–Hare Method)** is a classic approach where two pointers move at different speeds to detect cycles, find midpoints, or observe progression patterns in linked lists and arrays.

---

## 🧠 Concept Overview

| Pointer Type     | Description                         | Typical Use Case                                   |
| ---------------- | ----------------------------------- | -------------------------------------------------- |
| **Slow Pointer** | Moves one step at a time.           | Tracking progression gradually                     |
| **Fast Pointer** | Moves two steps at a time.          | Detecting cycles, reaching the end faster          |
| **Combined Use** | Fast catches slow if a loop exists. | Cycle detection, middle element, loop length, etc. |

---

# 🧭 Fast & Slow Pointer Problem Tracker

Track your progress on common **Fast–Slow Pointer Pattern** problems.

---

## 📊 Progress Table

| S No. | Problem No. | Problem Name                        | Difficulty | Platform      |
| :---: | :---------: | :---------------------------------- | :--------: | :------------ |
|   1   |     202     | Happy Number                        |    Easy    | LeetCode      |
|   2   |     876     | Middle of the Linked List           |    Easy    | LeetCode      |
|   3   |     141     | Linked List Cycle                   |    Easy    | LeetCode      |
|   4   |     142     | Linked List Cycle II                |   Medium   | LeetCode      |
|   5   |     N/A     | Find Length of Loop                 |   Medium   | GeeksForGeeks |
|   6   |     N/A     | Split a Linked List into Two Halves |    Easy    | GeeksForGeeks |
|   7   |     287     | Find the Duplicate Number           |   Medium   | LeetCode      |
|   8   |     234     | Palindrome Linked List              |   Medium   | LeetCode      |

---

## ⚙️ Core Idea

> Use two pointers where **fast moves twice** as fast as **slow**.  
> This makes it possible to detect cycles, find midpoints, and optimize algorithms from `O(n²)` to **O(n)**.
