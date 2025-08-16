# 🔁 Circular Linked List in C++

## 📌 What is a Circular Linked List?

A **Circular Linked List** is a linear data structure in which the last node points back to the first node, forming a circle. It allows continuous traversal and does not end in a `NULL` reference as in a regular singly linked list.

There are two main types:
- **Singly Circular Linked List**: Each node has a single pointer pointing to the next node; the last node's pointer links back to the first node.
- **Doubly Circular Linked List**: Each node contains two pointers, one pointing to the next node and another pointing to the previous node, forming a closed loop in both directions.

---

## 🔧 Why Use a Circular Linked List?

- Useful for applications requiring continuous iteration through a list without restarting.
- Efficient for scheduling, buffering, and implementing circular queues.
- Avoids the need to manually reset traversal pointers to the head after reaching the end.

---

## ✅ Features and Definitions

## 1. **Creation of a Circular Linked List**
This involves dynamically creating nodes and linking them in such a way that the last node's next pointer points back to the head node, completing the circle. It may start as an empty list and grow as nodes are inserted.

---

## 2. **Insertion Operations**

#### a. **Insert at Beginning**
Adds a new node at the start of the list. The new node becomes the head, and the last node's pointer is updated to point to this new head.

#### b. **Insert at End**
Appends a new node at the end of the list. The new node's next pointer points to the head, and the previous last node is updated to point to the new node.

#### c. **Insert at Specific Position**
Inserts a node at a user-defined index. The list is traversed until the required position is found, and the new node is inserted between existing nodes without breaking the circular link.

---

## 3. **Deletion Operations**

#### a. **Delete from Beginning**
Removes the head node. The head pointer is updated to the next node, and the last node is adjusted to point to the new head, maintaining the circular structure.

#### b. **Delete from End**
Removes the last node by traversing the list to the second-last node and updating its pointer to the head, thus removing the link to the old last node.

#### c. **Delete from Specific Position**
Removes a node located at a specific index. The node before the target node is updated to skip the deleted node, ensuring the circular structure remains intact.

---

## 4. **Traversal and Display**
Involves visiting each node in the list exactly once in a circular manner, starting from the head and looping back to it. Displaying the contents helps verify the integrity and order of the list.

---

## 5. **Search Operation**
Locates a node containing a specific value by traversing the list. If the value is found, its position or reference is returned; otherwise, the operation continues until it loops back to the head.

---

## 🧠 Advantages of Circular Linked List

- No need to reset pointers manually when end is reached.
- Ideal for designing circular structures like task schedulers or ring buffers.
- Efficient use of memory for repetitive or cyclical operations.

---

## 🧪 Use-Cases

- Real-time operating systems for round-robin CPU scheduling.
- Multiplayer board games where players take turns in a circular manner.
- Circular buffers used in embedded systems and streaming data.

---

🎯 Whether you're preparing for coding interviews or just brushing up your skills, you'll find this repo helpful!

👉 Feel free to ⭐ star this repo, fork it, or contribute your own improvements!

---