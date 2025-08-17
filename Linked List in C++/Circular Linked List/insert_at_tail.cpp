#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class circularList {
    Node *head;
    Node *tail;
    public:
    circularList() {
        head = tail = NULL;
    }

    void print() {
        if(head == NULL) {
            return ;
        }
        cout << head->data << "->";
        Node *temp = head->next;
        while(temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    void insertAtTail(int val) {
        Node *newNode = new Node(val);
        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main() {
    circularList clist;

    // Insert values at the tail
    clist.insertAtTail(10);
    clist.insertAtTail(20);
    clist.insertAtTail(30);

    // Print the circular linked list
    clist.print();  // Expected output: 10->20->30->10

    return 0;
}