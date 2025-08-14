# 🧮 Arrays and 2D Arrays in C++ – Definitions Only

This repository provides **clear definitions** of all major topics related to **arrays** and **2D arrays** in **C++**. It’s a concept-focused reference guide, ideal for interviews, revision, and foundational understanding.

---

## 📘 1. Array

An **array** is a collection of elements of the **same data type**, stored in **contiguous memory locations**, and accessed using **indexing**. Arrays in C++ are **static**, meaning their size is fixed at compile time.

**Syntax:**
```cpp
datatype arrayName[size];
```

**Example:**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

---

## 📘 2. One-Dimensional Array

A **one-dimensional array** (1D array) is a linear collection of elements, where each element can be accessed using a **single index**.

**Syntax:**
```cpp
int arr[3];
```

**Example:**
```cpp
arr[0] = 10;
```

---

## 📘 3. Two-Dimensional Array

A **two-dimensional array** (2D array) is an array of arrays. It represents a **matrix or table** and uses **two indices** — one for the row and one for the column — to access elements.

**Syntax:**
```cpp
datatype arrayName[rows][cols];
```

**Example:**
```cpp
int matrix[2][2] = {{1, 2}, {3, 4}};
```

---

## 📘 4. Array Traversal

**Array traversal** refers to the process of accessing each element of the array, usually in a loop, to perform operations such as reading, updating, or printing values.

**Syntax:**
```cpp
for (int i = 0; i < size; i++) { }
```

**Example:**
```cpp
for (int i = 0; i < 5; i++) cout << arr[i] << " ";
```

---

## 📘 5. Array Insertion

**Insertion** in an array involves adding an element at a specific index, which may require shifting other elements to make space. In static arrays, insertion is limited due to fixed size.

**Syntax:**
```cpp
arr[index] = value; // after shifting
```

**Example:**
```cpp
arr[2] = 99;
```

---

## 📘 6. Array Deletion

**Deletion** involves removing an element from a specific index and shifting subsequent elements leftward. In static arrays, deletion doesn’t shrink the array size.

**Syntax:**
```cpp
for (int i = index; i < n - 1; i++) arr[i] = arr[i + 1];
```

**Example:**
```cpp
arr[2] = arr[3];
```


---

## 📘 7. Searching in Arrays

**Searching** refers to the process of finding an element in the array. It can be done using **linear search** for unsorted arrays or **binary search** for sorted arrays.

**Syntax:**
```cpp
for (int i = 0; i < n; i++) if (arr[i] == key) return i;
```

**Example:**
```cpp
if (arr[i] == 3) cout << "Found";
```

---

## 📘 8. Sorting Arrays

**Sorting** an array arranges its elements in a particular order (ascending or descending). Common sorting algorithms include **bubble sort**, **selection sort**, and **merge sort**.

**Syntax:**
```cpp
for (...) if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
```

**Example:**
```cpp
sort(arr, arr + 5);
```

---

## 📘 9. Array as Function Parameter

Arrays can be passed to functions either by reference (decaying into pointers) or using pointers explicitly. C++ does not pass arrays by value.

**Syntax:**
```cpp
void func(int arr[], int n);
```

**Example:**
```cpp
printArray(arr, 5);
```


---

## 📘 10. Pointers and Arrays

In C++, the name of the array acts as a pointer to the first element. Arrays and pointers are closely related, but not identical. Pointer arithmetic allows navigation through array elements.

**Syntax:**
```cpp
int* ptr = arr;
```

**Example:**
```cpp
cout << *(arr + 1);
```


---

## 📘 11. Dynamic Arrays

A **dynamic array** is an array whose size is allocated at runtime using heap memory (typically via `new` keyword in C++). Dynamic arrays allow flexible sizing.

**Syntax:**
```cpp
int* arr = new int[size];
```

**Example:**
```cpp
arr[0] = 42;
```


---

## 📘 12. Deallocation of Dynamic Arrays

To avoid memory leaks, dynamically allocated arrays must be deallocated using the `delete[]` keyword.

**Syntax:**
```cpp
delete[] arr;
```

**Example:**
```cpp
delete[] arr;
```


---

## 📘 13. STL Array

`std::array` is a **container** in the Standard Template Library (STL) that wraps a fixed-size array and provides additional member functions and safety features like bounds checking.

**Syntax:**
```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};
```

**Example:**
```cpp
cout << arr.at(2);
```


---

## 📘 14. Vector (Dynamic Array)

`std::vector` is a **dynamic array** from the STL that can grow and shrink in size at runtime. It provides rich functionality and handles memory management internally.

**Syntax:**
```cpp
std::vector<int> vec;
```

**Example:**
```cpp
vec.push_back(10);
```


---

## 📘 15. Multidimensional Arrays

Multidimensional arrays (e.g., 3D arrays) are extensions of 2D arrays, representing data with more than two dimensions. Each additional dimension adds a layer of indexing.

**Syntax:**
```cpp
int arr[x][y][z];
```

**Example:**
```cpp
arr[0][1][2] = 5;
```


---

## 📘 16. Jagged Arrays

A **jagged array** is an array of arrays where each sub-array may have different lengths. In C++, this is typically implemented using an array of pointers or `std::vector<vector<int>>`.

**Syntax:**
```cpp
int* jagged[3];
```

**Example:**
```cpp
jagged[0] = new int[2];
```


---

## 📘 17. Memory Layout of Arrays

Arrays are stored in **contiguous memory blocks**. In 2D arrays, **row-major order** is the standard layout in C++, meaning rows are stored one after the other in memory.

**Syntax:**
```cpp
// Not directly applicable; conceptual
```

**Example:**
```cpp
cout << &arr[0] << " " << &arr[1];
```


---

## 📘 18. Limitations of Static Arrays

Static arrays in C++:
- Cannot change size at runtime
- Cannot be returned from functions by value (without using structs/classes)
- Risk out-of-bounds access due to lack of bounds checking

**Syntax:**
```cpp
int arr[100]; // Fixed at compile time
```

**Example:**
```cpp
arr[101] = 5; // Unsafe
```


---

## 📘 19. Benefits of Using Arrays

- Fast random access (O(1))
- Memory efficiency for fixed-size data
- Simplicity and low overhead compared to dynamic structures

**Syntax:**
```cpp
// Conceptual
```

**Example:**
```cpp
int x = arr[3]; // O(1) access
```


---

## 📘 20. Use Cases of Arrays

- Storing fixed-size collections
- Implementing data structures like stacks, queues, heaps
- Matrix operations, image processing (2D arrays)
- Competitive programming and algorithm practice

**Syntax:**
```cpp
// Conceptual
```

**Example:**
```cpp
int stack[100]; // Stack implemented using array
```


---

## 🧠 Summary Table

## 🧠 Summary Table

| Topic                  | Definition Summary                                    | Syntax Example                   |
|------------------------|------------------------------------------------------|--------------------------------|
| Array                  | Fixed-size collection of elements of the same type   | `int arr[5];`                  |
| One-Dimensional Array  | Linear array accessed by a single index               | `int arr[3];`                  |
| Two-Dimensional Array  | Array of arrays, used to represent matrices           | `int mat[3][3];`               |
| Array Traversal        | Process of visiting each element                       | `for (int i=0; i<n; i++)`      |
| Array Insertion        | Adding element by shifting elements                     | `arr[index] = value;`          |
| Array Deletion         | Removing element by shifting elements                   | `for (int i=index; i<n-1; i++) arr[i]=arr[i+1];` |
| Searching in Arrays    | Finding element using linear or binary search          | `if(arr[i] == key)`            |
| Sorting Arrays         | Arranging elements in order                             | `sort(arr, arr+n);`             |
| Array as Function Param| Passing array to function                               | `void func(int arr[], int n);` |
| Pointers and Arrays    | Array name acts as pointer to first element            | `int* ptr = arr;`              |
| Dynamic Arrays         | Arrays allocated at runtime                             | `int* arr = new int[n];`       |
| Deallocation of Dynamic Arrays | Freeing dynamic memory                          | `delete[] arr;`                |
| STL Array              | Fixed-size wrapper from STL                             | `std::array<int, 5> arr;`      |
| Vector (Dynamic Array) | Resizable array from STL                                | `std::vector<int> vec;`        |
| Multidimensional Arrays| Arrays with more than 2 dimensions                      | `int arr[x][y][z];`            |
| Jagged Arrays          | Arrays of arrays with different lengths                | `int* jagged[3];`              |
| Memory Layout of Arrays| Contiguous memory, row-major for 2D arrays             | `&arr[0]`, `&arr[1]`           |
| Limitations of Static Arrays | Fixed size, no runtime resizing                   | `int arr[100];`                |
| Benefits of Using Arrays| Fast access, cache friendly                            | `int x = arr[3];`              |
| Use Cases of Arrays    | Used in algorithms, data structures, matrices          | `int stack[100];`              |


---

🎯 Whether you're preparing for coding interviews or just brushing up your skills, you'll find this repo helpful!

👉 Feel free to ⭐ star this repo, fork it, or contribute your own improvements!

---