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
```

---

### 🎯 Object  
An **object** is an instance of a class that has a unique identity, state, and behavior.
**Example:**
```cpp
Car myCar;
```

---

## 🏗 Constructor  
A **constructor** is a special member function that initializes objects when they are created.  
It has the same name as the class and no return type.
**Example:**
```cpp
class Car { public: Car() { } };
```

#### 🔹 Types of Constructors  
- **Default Constructor** – Initializes objects with default values.
**Example:**
```cpp
class Car { public: Car() { speed = 0; } int speed; };
```

- **Parameterized Constructor** – Initializes objects with given values. 
**Example:**
```cpp
class Car { public: Car(int s) { speed = s; } int speed; };
```

- **Copy Constructor** – Initializes a new object as a copy of another object.
**Example:**
```cpp
Car(Car &c) { speed = c.speed; }
```

- **Explicit Constructor** – Prevents implicit type conversions.  
**Example:**
```cpp
explicit Car(int s) { speed = s; }
```

- **Delegating Constructor** – Calls another constructor in the same class.
**Example:**
```cpp
Car() : Car(0) {}
```

---

## 🔄 Inheritance  
**Inheritance** is a mechanism by which one class (derived class) can acquire properties and behaviors of another class (base class).
**Example:**
```cpp
class Car {}; class SportsCar : public Car {};
```

#### 🧬 Types of Inheritance  
- **Single Inheritance** – One derived class inherits from one base class.  
**Example:**
```cpp
class A {}; class B : public A {};
```

- **Multiple Inheritance** – One derived class inherits from multiple base classes.  
**Example:**
```cpp
class A {}; class B {}; class C : public A, public B {};
```

- **Multilevel Inheritance** – A class is derived from another derived class.  
**Example:**
```cpp
class A {}; class B : public A {}; class C : public B {};
```

- **Hierarchical Inheritance** – Multiple derived classes inherit from one base class. 
**Example:**
```cpp
class A {}; class B : public A {}; class C : public A {};
```

- **Hybrid Inheritance** – A combination of two or more types of inheritance.
**Example:**
```cpp
class A {}; class B : virtual public A {}; class C : virtual public A {}; class D : public B, public C {};
```

---

### 🕵 Abstraction  
**Abstraction** is the process of hiding implementation details and showing only the necessary features to the user.
**Example:**
```cpp
class Shape { public: virtual void draw() = 0; };
```

---

### 🔐 Encapsulation  
**Encapsulation** is the bundling of data and methods into a single unit and restricting access to some components.
**Example:**
```cpp
class Account { private: double balance; public: void deposit(double amt) { balance += amt; } };
```

---

### 🎭 Polymorphism  
**Polymorphism** is the ability of a function, operator, or object to behave differently based on the context.
**Example:**
```cpp
class Shape { public: virtual void draw() {} }; class Circle : public Shape { public: void draw() {} };
```

---

#### 🔹 Function Overloading  
Multiple functions with the same name but different parameter lists in the same scope.
**Example:**
```cpp
void print(int x); void print(double y);
```

#### 🔹 Function Overriding  
A derived class provides a specific implementation of a function already defined in its base class.
**Example:**
```cpp
class A { public: virtual void show() {} }; class B : public A { public: void show() override {} };
```

#### 🔹 Operator Overloading  
Redefining the meaning of an operator for user-defined data types.
**Example:**
```cpp
class Point { public: int x; Point operator+(Point p) { return {x + p.x}; } };
```

---

### 📌 Static Data Member  
A **static data member** belongs to the class rather than objects, meaning all objects share the same variable.
**Example:**
```cpp
class Test { public: static int count; };
```

---

### 🌀 Virtual Function  
A **virtual function** is a member function declared in a base class and redefined in a derived class to achieve runtime polymorphism.
**Example:**
```cpp
class Base { public: virtual void display() {} };
```

---

### 👉 this Keyword  
The **this** keyword is a pointer to the calling object and is used to access its members.
**Example:**
```cpp
void setSpeed(int speed) { this->speed = speed; }
```

---

## 📜 Additional Important Concepts

### 🛠 Destructor  
A **destructor** is a special member function that destroys an object when it is no longer needed.
**Example:**
```cpp
~Car() { }
```

---

### 🛡 Access Specifiers  
Control the accessibility of class members:  
- **public** – Accessible from anywhere.  
- **private** – Accessible only within the class.  
- **protected** – Accessible within the class and its derived classes.
**Example:**
```cpp
class Example { public: int a; private: int b; protected: int c; };
```

---

### ⏳ Friend Function  
A **friend function** is a non-member function that has access to the private and protected members of a class.
**Example:**
```cpp
class Test { friend void show(Test t); };
```

---

### 🔄 Virtual Destructor  
A **virtual destructor** ensures that the correct destructor is called for an object when deleted through a base class pointer.
**Example:**
```cpp
virtual ~Base() {}
```

---

### 📥 Pure Virtual Function  
A **pure virtual function** has no implementation in the base class and must be overridden in the derived class.
**Example:**
```cpp
virtual void display() = 0;
```

---

### 🧩 Abstract Class  
A **class** that contains at least one pure virtual function and cannot be instantiated.
**Example:**
```cpp
class Abstract { virtual void run() = 0; };
```

---

### 📤 Inline Function  
A function whose definition is expanded in place where it is called, to reduce function call overhead.
**Example:**
```cpp
inline int add(int a, int b) { return a + b; }
```

---

### 🔁 Deep Copy vs Shallow Copy  
- **Shallow Copy** – Copies only data members, not dynamically allocated memory.  
**Example:**
```cpp
ClassName obj2 = obj1;
```

- **Deep Copy** – Copies data members along with dynamically allocated memory.
**Example:**
```cpp
ClassName(const ClassName &obj) { ptr = new int(*obj.ptr); }
```

---

## 🚀 Advanced OOP Concepts in C++

### 🧵 Mutable Keyword  
Allows modification of a data member even in a `const` function.
**Example:**
```cpp
mutable int cache;
```

### 🎯 Explicit Keyword  
Prevents unintended implicit type conversions for constructors.
**Example:**
```cpp
explicit MyClass(int x) {}
```

---

### 🗃 Namespace  
Logical grouping of identifiers to prevent naming conflicts.
**Example:**
```cpp
namespace MySpace { int x; }
```

---

### 🪝 Virtual Table (vtable)  
A mechanism used to support dynamic dispatch of virtual functions.
**Example:**
```cpp
(Implicitly created by compiler when using virtual functions)
```

---

### 🧩 Interface (Pure Abstract Class)  
A class containing only pure virtual functions, used to define a contract.
**Example:**
```cpp
class IShape { virtual void draw() = 0; };
```

---

### 📌 Final Specifier  
Prevents a class from being inherited or a virtual function from being overridden.
**Example:**
```cpp
class MyClass final {};
```

---

### ⚙ Overriding vs Hiding  
- **Overriding** – Derived class replaces base class function with same signature.  
- **Hiding** – Derived class function with same name but different parameters hides base class version.
**Example:**
```cpp
void display(int x); // hides base display()
```

---

### ⏱ Static Member Function  
Belongs to the class, not objects, and can only access static members.
**Example:**
```cpp
static void showCount();
```

---

### 🔗 Multiple Virtual Inheritance  
Solves ambiguity when multiple base classes share the same ancestor.
**Example:**
```cpp
class A {}; class B : virtual public A {}; class C : virtual public A {};
```

---

### 🛠 Const Member Function  
Member function that cannot modify the object’s data.
**Example:**
```cpp
int getValue() const { return value; }
```

---

### 🎛 Accessor and Mutator  
- **Accessor** – Retrieves private data (getter).  
**Example:**
```cpp
int getValue();
```

- **Mutator** – Modifies private data (setter).
**Example:**
```cpp
void setValue(int v);
```

---

### 📦 Aggregation  
A "has-a" relationship where the child object can exist independently of the parent.
**Example:**
```cpp
class Engine {}; class Car { Engine e; };
```

---

### 🔗 Composition  
A "has-a" relationship where the child object's lifetime depends on the parent.
**Example:**
```cpp
class Heart {}; class Human { Heart h; };
```

---

### 🪄 Type Casting in OOP  
- **static_cast** – Compile-time type conversion. 
**Example:**
```cpp
int x = static_cast<int>(3.5);
```

- **dynamic_cast** – Safe downcasting in inheritance.
**Example:**
```cpp
Derived* d = dynamic_cast<Derived*>(basePtr);
```

- **reinterpret_cast** – Low-level bit reinterpretation.  
**Example:**
```cpp
char* p = reinterpret_cast<char*>(&num);
```

- **const_cast** – Adds or removes `const` qualifier.
**Example:**
```cpp
int* p = const_cast<int*>(&num);
```

---

### 🛠 Member Initializer List  
Initializes class members before the constructor body executes.
**Example:**
```cpp
Car() : speed(0) {}
```

---

### ⚠ Diamond Problem  
Ambiguity in multiple inheritance when two parent classes share a common base.
**Example:**
```cpp
class A {}; class B : public A {}; class C : public A {}; class D : public B, public C {};
```

---

### 🎯 Virtual Base Class  
Used to solve the diamond problem by sharing a single base class instance.
**Example:**
```cpp
class A {}; class B : virtual public A {}; class C : virtual public A {};
```

---

### 🛡 Private Inheritance  
When a class inherits privately, base class members become private in the derived class.
**Example:**
```cpp
class B : private A {};
```

---

## 📌 Summary  
OOP in C++ promotes **code reusability**, **modularity**, **security**, and **maintainability** through concepts like **classes**, **inheritance**, **abstraction**, **encapsulation**, and **polymorphism**.

---

⭐ If you find this helpful, consider giving it a star!

I kept **every original definition untouched** and attached **shortest possible examples**.  
If you want, I can now **format these examples in collapsible `<details>` blocks** so they stay hidden until clicked, making the README cleaner. That would be great for GitHub readability.

---