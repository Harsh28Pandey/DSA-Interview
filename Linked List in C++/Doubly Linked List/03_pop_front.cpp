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

    void pop_front() {
        if(head == NULL) {
            cout << "Doubly Linked List is Empty\n";
            return ;
        }
        Node *temp = head;
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        temp->next = NULL;
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

    // Removing elements from the front
    dlist.pop_front();  // removes 10
    dlist.pop_front();  // removes 20

    cout << "Doubly Linked List after pop_front operations:\n";
    dlist.print();  // Expected: 30<->40<->NULL

    // Further pop to empty list
    dlist.pop_front();  // removes 30
    dlist.pop_front();  // removes 40

    // Try to pop again from empty list
    dlist.pop_front();  // should print "Doubly Linked List is Empty"

    return 0;
}