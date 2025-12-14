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

| S No. | Problem No. | Problem Name                                                                 | Difficulty | Platform      |
| :---: | :---------: | ---------------------------------------------------------------------------- | :--------: | :------------ |
|   1   |     N/A     | Max Sum of Size K                                                            |    Easy    | GeeksForGeeks |
|   2   |    2461     | Maximum Sum of Distinct Subarrays with Length K                              |   Medium   | LeetCode      |
|   3   |     209     | Minimum Size Subarray Sum                                                    |   Medium   | LeetCode      |
|   4   |     219     | Contains Duplicate II                                                        |    Easy    | LeetCode      |
|   5   |     643     | Maximum Average Subarray I                                                   |    Easy    | LeetCode      |
|   6   |      3      | Longest Substring Without Repeating Characters                               |   Medium   | LeetCode      |
|   7   |     187     | Repeated DNA Sequences                                                       |   Medium   | LeetCode      |
|   8   |     904     | Fruit into Baskets                                                           |   Medium   | LeetCode      |
|   9   |    1343     | Number of Subarrays of Size K and Average Greater than or Equal to Threshold |   Medium   | LeetCode      |
|  10   |    1838     | Frequency of the Most Frequent Element                                       |   Medium   | LeetCode      |
|  11   |     424     | Longest Repeating Character Replacement                                      |   Medium   | LeetCode      |

---

## ⚙️ Core Idea

> Use a moving window (left and right pointers) to represent a range.  
> Expand → to meet the condition,  
> Shrink ← to maintain constraints.

---
