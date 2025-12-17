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

    void push_front(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
};

int main() {
    doublyList dlist;

    dlist.push_front(10);
    dlist.push_front(20);
    dlist.push_front(30);

    cout << "Doubly Linked List (after inserting at front): ";
    dlist.print();  // Expected: 30<->20<->10<->NULL

    return 0;
}