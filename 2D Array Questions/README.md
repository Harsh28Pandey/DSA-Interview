# 🧮 Arrays and 2D Arrays in C++ – Definitions Only

This repository provides **clear definitions** of all major topics related to **arrays** and **2D arrays** in **C++**. It’s a concept-focused reference guide, ideal for interviews, revision, and foundational understanding.

---

## 📘 1. Array

An **array** is a collection of elements of the **same data type**, stored in **contiguous memory locations**, and accessed using **indexing**. Arrays in C++ are **static**, meaning their size is fixed at compile time.

---

## 📘 2. One-Dimensional Array

A **one-dimensional array** (1D array) is a linear collection of elements, where each element can be accessed using a **single index**.

---

## 📘 3. Two-Dimensional Array

A **two-dimensional array** (2D array) is an array of arrays. It represents a **matrix or table** and uses **two indices** — one for the row and one for the column — to access elements.

---

## 📘 4. Array Traversal

**Array traversal** refers to the process of accessing each element of the array, usually in a loop, to perform operations such as reading, updating, or printing values.

---

## 📘 5. Array Insertion

**Insertion** in an array involves adding an element at a specific index, which may require shifting other elements to make space. In static arrays, insertion is limited due to fixed size.

---

## 📘 6. Array Deletion

**Deletion** involves removing an element from a specific index and shifting subsequent elements leftward. In static arrays, deletion doesn’t shrink the array size.

---

## 📘 7. Searching in Arrays

**Searching** refers to the process of finding an element in the array. It can be done using **linear search** for unsorted arrays or **binary search** for sorted arrays.

---

## 📘 8. Sorting Arrays

**Sorting** an array arranges its elements in a particular order (ascending or descending). Common sorting algorithms include **bubble sort**, **selection sort**, and **merge sort**.

---

## 📘 9. Array as Function Parameter

Arrays can be passed to functions either by reference (decaying into pointers) or using pointers explicitly. C++ does not pass arrays by value.

---

## 📘 10. Pointers and Arrays

In C++, the name of the array acts as a pointer to the first element. Arrays and pointers are closely related, but not identical. Pointer arithmetic allows navigation through array elements.

---

## 📘 11. Dynamic Arrays

A **dynamic array** is an array whose size is allocated at runtime using heap memory (typically via `new` keyword in C++). Dynamic arrays allow flexible sizing.

---

## 📘 12. Deallocation of Dynamic Arrays

To avoid memory leaks, dynamically allocated arrays must be deallocated using the `delete[]` keyword.

---

## 📘 13. STL Array

`std::array` is a **container** in the Standard Template Library (STL) that wraps a fixed-size array and provides additional member functions and safety features like bounds checking.

---

## 📘 14. Vector (Dynamic Array)

`std::vector` is a **dynamic array** from the STL that can grow and shrink in size at runtime. It provides rich functionality and handles memory management internally.

---

## 📘 15. Multidimensional Arrays

Multidimensional arrays (e.g., 3D arrays) are extensions of 2D arrays, representing data with more than two dimensions. Each additional dimension adds a layer of indexing.

---

## 📘 16. Jagged Arrays

A **jagged array** is an array of arrays where each sub-array may have different lengths. In C++, this is typically implemented using an array of pointers or `std::vector<vector<int>>`.

---

## 📘 17. Memory Layout of Arrays

Arrays are stored in **contiguous memory blocks**. In 2D arrays, **row-major order** is the standard layout in C++, meaning rows are stored one after the other in memory.

---

## 📘 18. Limitations of Static Arrays

Static arrays in C++:
- Cannot change size at runtime
- Cannot be returned from functions by value (without using structs/classes)
- Risk out-of-bounds access due to lack of bounds checking

---

## 📘 19. Benefits of Using Arrays

- Fast random access (O(1))
- Memory efficiency for fixed-size data
- Simplicity and low overhead compared to dynamic structures

---

## 📘 20. Use Cases of Arrays

- Storing fixed-size collections
- Implementing data structures like stacks, queues, heaps
- Matrix operations, image processing (2D arrays)
- Competitive programming and algorithm practice

---

## 🧠 Summary Table

| Concept                  | Definition Summary                                             |
|--------------------------|---------------------------------------------------------------|
| Array                    | Fixed-size collection of elements of the same type            |
| 1D Array                 | Linear array using single index                               |
| 2D Array                 | Matrix-like structure using two indices                       |
| Dynamic Array            | Resizable array using heap memory                             |
| STL Array                | Safer, fixed-size wrapper over traditional array              |
| Vector                   | Dynamic array with automatic memory management                |
| Pointer & Array          | Array names decay to pointers, allowing pointer arithmetic    |
| Jagged Array             | Array of arrays with varying lengths                          |

---

🎯 Whether you're preparing for coding interviews or just brushing up your skills, you'll find this repo helpful!

👉 Feel free to ⭐ star this repo, fork it, or contribute your own improvements!

---