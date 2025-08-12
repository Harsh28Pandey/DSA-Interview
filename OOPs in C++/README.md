# 💻 OOPs Concepts in C++

This repository contains concise definitions of important **Object-Oriented Programming (OOP)** concepts in **C++**.  
OOP is a programming paradigm that organizes software design around **objects** rather than functions and logic.

---

## 📚 Key OOP Concepts

### 🏛 Class  
A **class** is a user-defined data type that acts as a blueprint for creating objects. It encapsulates data (attributes) and functions (methods) into a single unit.

**Example:**  
```cpp
class Car { public: int speed; void drive() {} };

### 🎯 Object  
An **object** is an instance of a class that has a unique identity, state, and behavior.

### 🏗 Constructor  
A **constructor** is a special member function that initializes objects when they are created.  
It has the same name as the class and no return type.

#### 🔹 Types of Constructors  
- **Default Constructor** – Initializes objects with default values. 
- **Parameterized Constructor** – Initializes objects with given values.  
- **Copy Constructor** – Initializes a new object as a copy of another object.
- **Explicit Constructor** – Prevents implicit type conversions.  
- **Delegating Constructor** – Calls another constructor in the same class.

### 🔄 Inheritance  
**Inheritance** is a mechanism by which one class (derived class) can acquire properties and behaviors of another class (base class).

#### 🧬 Types of Inheritance  
- **Single Inheritance** – One derived class inherits from one base class.  
- **Multiple Inheritance** – One derived class inherits from multiple base classes.  
- **Multilevel Inheritance** – A class is derived from another derived class.  
- **Hierarchical Inheritance** – Multiple derived classes inherit from one base class.  
- **Hybrid Inheritance** – A combination of two or more types of inheritance.

### 🕵 Abstraction  
**Abstraction** is the process of hiding implementation details and showing only the necessary features to the user.

### 🔐 Encapsulation  
**Encapsulation** is the bundling of data and methods into a single unit and restricting access to some components.

### 🎭 Polymorphism  
**Polymorphism** is the ability of a function, operator, or object to behave differently based on the context.

#### 🔹 Function Overloading  
Multiple functions with the same name but different parameter lists in the same scope.

#### 🔹 Function Overriding  
A derived class provides a specific implementation of a function already defined in its base class.

#### 🔹 Operator Overloading  
Redefining the meaning of an operator for user-defined data types.

### 📌 Static Data Member  
A **static data member** belongs to the class rather than objects, meaning all objects share the same variable.

### 🌀 Virtual Function  
A **virtual function** is a member function declared in a base class and redefined in a derived class to achieve runtime polymorphism.

### 👉 this Keyword  
The **this** keyword is a pointer to the calling object and is used to access its members.

---

## 📜 Additional Important Concepts

### 🛠 Destructor  
A **destructor** is a special member function that destroys an object when it is no longer needed.

### 🛡 Access Specifiers  
Control the accessibility of class members:  
- **public** – Accessible from anywhere.  
- **private** – Accessible only within the class.  
- **protected** – Accessible within the class and its derived classes.

### ⏳ Friend Function  
A **friend function** is a non-member function that has access to the private and protected members of a class.

### 🔄 Virtual Destructor  
A **virtual destructor** ensures that the correct destructor is called for an object when deleted through a base class pointer.

### 📥 Pure Virtual Function  
A **pure virtual function** has no implementation in the base class and must be overridden in the derived class.

### 🧩 Abstract Class  
A **class** that contains at least one pure virtual function and cannot be instantiated.

### 📤 Inline Function  
A function whose definition is expanded in place where it is called, to reduce function call overhead.

### 🔁 Deep Copy vs Shallow Copy  
- **Shallow Copy** – Copies only data members, not dynamically allocated memory.  
- **Deep Copy** – Copies data members along with dynamically allocated memory.

---

## 🚀 Advanced OOP Concepts in C++

### 🧵 Mutable Keyword  
Allows modification of a data member even in a `const` function.

### 🎯 Explicit Keyword  
Prevents unintended implicit type conversions for constructors.

### 🗃 Namespace  
Logical grouping of identifiers to prevent naming conflicts.

### 🪝 Virtual Table (vtable)  
A mechanism used to support dynamic dispatch of virtual functions.

### 🧩 Interface (Pure Abstract Class)  
A class containing only pure virtual functions, used to define a contract.

### 📌 Final Specifier  
Prevents a class from being inherited or a virtual function from being overridden.

### ⚙ Overriding vs Hiding  
- **Overriding** – Derived class replaces base class function with same signature.  
- **Hiding** – Derived class function with same name but different parameters hides base class version.

### ⏱ Static Member Function  
Belongs to the class, not objects, and can only access static members.

### 🔗 Multiple Virtual Inheritance  
Solves ambiguity when multiple base classes share the same ancestor.

### 🛠 Const Member Function  
Member function that cannot modify the object’s data.

### 🎛 Accessor and Mutator  
- **Accessor** – Retrieves private data (getter).  
- **Mutator** – Modifies private data (setter).

### 📦 Aggregation  
A "has-a" relationship where the child object can exist independently of the parent.

### 🔗 Composition  
A "has-a" relationship where the child object's lifetime depends on the parent.

### 🪄 Type Casting in OOP  
- **static_cast** – Compile-time type conversion.  
- **dynamic_cast** – Safe downcasting in inheritance.  
- **reinterpret_cast** – Low-level bit reinterpretation.  
- **const_cast** – Adds or removes `const` qualifier.

### 🛠 Member Initializer List  
Initializes class members before the constructor body executes.

### ⚠ Diamond Problem  
Ambiguity in multiple inheritance when two parent classes share a common base.

### 🎯 Virtual Base Class  
Used to solve the diamond problem by sharing a single base class instance.

### 🛡 Private Inheritance  
When a class inherits privately, base class members become private in the derived class.

---

## 📌 Summary  
OOP in C++ promotes **code reusability**, **modularity**, **security**, and **maintainability** through concepts like **classes**, **inheritance**, **abstraction**, **encapsulation**, and **polymorphism**.

---

⭐ If you find this helpful, consider giving it a star!
