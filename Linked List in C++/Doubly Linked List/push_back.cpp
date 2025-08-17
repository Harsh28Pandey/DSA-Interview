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
};

int main() {
    doublyList dlist;

    // Insert elements at the back
    dlist.push_back(10);
    dlist.push_back(20);
    dlist.push_back(30);
    dlist.push_back(40);

    // Print the list
    cout << "Doubly Linked List (after inserting at back): ";
    dlist.print();  // Expected output: 10<->20<->30<->40<->NULL

    return 0;
}