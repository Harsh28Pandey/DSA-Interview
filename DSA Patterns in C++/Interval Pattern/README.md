# ⏱️ Interval Pattern in C++ DSA

The **Interval Pattern** is a common technique used to solve problems involving **ranges, time intervals, or segments**.  
It is especially useful for problems related to **merging intervals, scheduling, overlapping ranges, and conflicts**.

This pattern typically involves **sorting intervals** and then processing them in a structured way to achieve optimal results.

---

## 🧠 Concept Overview

| Interval Type        | Description                            | Typical Use Case                               |
| -------------------- | -------------------------------------- | ---------------------------------------------- |
| **Overlapping**      | Intervals that share common points     | Merge intervals, meeting room problems         |
| **Non-Overlapping**  | Intervals that do not intersect        | Interval scheduling, conflict-free selection   |
| **Nested Intervals** | One interval completely inside another | Removing covered intervals                     |
| **Touching**         | End of one equals start of another     | Can be merged or kept separate (problem-based) |

---

# 🧭 Interval Pattern Problem Tracker

Track your progress on important **Interval-Based Problems** in C++.

---

## 📊 Progress Table

| S No. | Problem No. | Problem Name | Difficulty | Platform |
| :---: | :---------: | ------------ | :--------: | :------- |
|       |             |              |            |          |

---

## ⚙️ Core Idea

> Sort intervals (usually by **start time**).  
> Compare current interval with the previous one.
>
> - **Merge** if overlapping
> - **Count / discard / select** based on problem constraints

---
