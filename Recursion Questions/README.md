# 🔁 Recursion & 🔙 Backtracking in C++

This repository is a comprehensive resource for **Recursion** and **Backtracking** algorithms implemented in **C++**. It covers foundational concepts, best practices, and real-world use cases. Perfect for students, interview prep, or anyone looking to master problem-solving with recursive techniques!

---

## 📘 What is Recursion?

Recursion is a programming technique where a function **calls itself** to solve a smaller instance of the same problem. Every recursive function has two main parts:

- 🧱 **Base Case**: The stopping condition that prevents infinite recursion.
- 🔁 **Recursive Case**: The part where the function calls itself with a smaller/simpler input.

### 🧠 Key Concepts:

- **Call Stack**: Each recursive call is pushed onto the stack; when the base case is reached, calls start returning in reverse order.
- **Tail Recursion**: A special case where the recursive call is the last statement in the function (can be optimized by the compiler).
- **Direct vs Indirect Recursion**: A function can call itself directly or through another function.

---

## 🔙 What is Backtracking?

Backtracking is an algorithmic technique to **build solutions incrementally**, abandoning a path ("backtrack") as soon as it is determined it cannot lead to a valid solution.

### 🧩 Use Cases:

- ✅ **N-Queens Problem**
- ✅ **Sudoku Solver**
- ✅ **Maze Solving**
- ✅ **Permutations / Combinations**
- ✅ **Subset Generation**
- ✅ **Word Search in Matrix**

### 📘 Definition:

Backtracking is a **refined form of recursion** used for solving constraint satisfaction problems. It explores all possible options and **prunes** the invalid ones early, making it efficient for exponential search spaces.

---

## ⏱️ Time and 💾 Space Complexity (Varies by Problem)

| Problem Type            | Time Complexity            | Space Complexity         |
|-------------------------|----------------------------|--------------------------|
| Factorial               | O(n)                       | O(n)                     |
| Fibonacci (naive)       | O(2^n)                     | O(n)                     |
| Fibonacci (memoized)    | O(n)                       | O(n)                     |
| N-Queens                | O(N!)                      | O(N²)                    |
| Permutations            | O(n × n!)                  | O(n)                     |
| Subsets (power set)     | O(2^n)                     | O(n)                     |

---

## 🧪 Example Recursive Topics Covered

- ✅ Factorial of a number  
- ✅ Fibonacci sequence  
- ✅ Sum of digits  
- ✅ Power of a number  
- ✅ Palindrome check  
- ✅ Tower of Hanoi  
- ✅ Recursively reverse an array/string  
- ✅ Recursively check for sorted array  
- ✅ Recursive binary search  
- ✅ Generate all subsets/permutations  
- ✅ Backtracking: N-Queens, Sudoku, Rat in a Maze  

---

🎯 Whether you're preparing for coding interviews or just brushing up your skills, you'll find this repo helpful!

👉 Feel free to ⭐ star this repo, fork it, or contribute your own improvements!

---