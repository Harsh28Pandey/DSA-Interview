# 🌬️ Sliding Window Pattern in C++ DSA

The **Sliding Window Technique** is a powerful optimization strategy for solving problems involving **contiguous subarrays or substrings**.  
It helps reduce time complexity from `O(n²)` → **O(n)** by moving a window over the data instead of using nested loops.

---

## 🧠 Concept Overview

| Window Type         | Description                                     | Typical Use Case                               |
| ------------------- | ----------------------------------------------- | ---------------------------------------------- |
| **Fixed Window**    | Window size remains constant                    | Max sum of size K, average of K elements       |
| **Variable Window** | Window expands and shrinks based on a condition | Longest substring without repeating characters |
| **Dynamic Window**  | Uses maps/sets to maintain state efficiently    | Subarrays with at most K distinct numbers      |

---

# 🧭 Sliding Window Problem Tracker

Track your progress on important **Sliding Window Problems** in C++.

---

## 📊 Progress Table

| S No. | Problem No. | Problem Name                                    | Difficulty | Platform      |
| :---: | :---------: | ----------------------------------------------- | :--------: | :------------ |
|   1   |     N/A     | Max Sum of Size K                               |    Easy    | GeeksForGeeks |
|   2   |    2461     | Maximum Sum of Distinct Subarrays with Length K |   Medium   | LeetCode      |
|   3   |     209     | Minimum Size Subarray Sum                       |   Medium   | LeetCode      |
|   3   |     219     | Contains Duplicate II                           |    Easy    | LeetCode      |
|   3   |     643     | Maximum Average Subarray I                      |    Easy    | LeetCode      |
|   3   |      3      | Longest Substring Without Repeating Characters  |   Medium   | LeetCode      |

---

## ⚙️ Core Idea

> Use a moving window (left and right pointers) to represent a range.  
> Expand → to meet the condition,  
> Shrink ← to maintain constraints.

---
