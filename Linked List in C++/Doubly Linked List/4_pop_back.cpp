#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class doublyList {
    Node *head;
    Node *tail;
    public:
    doublyList() {
        head = tail = NULL;
    }

    void print() {
        Node *temp = head;
        while(temp != NULL) {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void push_back(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() {
        if(head == NULL) {
            cout << "Doubly Linked List is Empty\n";
            return ;
        }
        Node *temp = tail;
        tail = tail->prev;
        if(tail != NULL) {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }
};

int main() {
    doublyList dlist;

    // Inserting elements at the back
    dlist.push_back(10);
    dlist.push_back(20);
    dlist.push_back(30);
    dlist.push_back(40);

    cout << "Doubly Linked List after push_back operations:\n";
    dlist.print();  // Expected: 10<->20<->30<->40<->NULL

    // Removing elements from the back
    dlist.pop_back();  // removes 40
    dlist.pop_back();  // removes 30

    cout << "Doubly Linked List after pop_back operations:\n";
    dlist.print();  // Expected: 10<->20<->NULL

    // Remove remaining nodes
    dlist.pop_back();  // removes 20
    dlist.pop_back();  // removes 10

    // Try to remove from an empty list
    dlist.pop_back();  // should show "Doubly Linked List is Empty"

    return 0;
}