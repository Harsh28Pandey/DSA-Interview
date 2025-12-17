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

    void deleteAtHead() {
        if(head == NULL) {
            return ;
        }
        else if(head == tail) { // single node
            delete head;
            head = tail = NULL;
        }
        else { // two or more node
            Node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
};

int main() {
    circularList clist;

    // Insert nodes at tail (I'll add this function here for testing)
    clist.insertAtTail(10);
    clist.insertAtTail(20);
    clist.insertAtTail(30);

    cout << "Original list: ";
    clist.print();  // Expected: 10->20->30->10

    // Delete head node
    clist.deleteAtHead();
    cout << "After deleting head: ";
    clist.print();  // Expected: 20->30->20

    // Delete head again
    clist.deleteAtHead();
    cout << "After deleting head again: ";
    clist.print();  // Expected: 30->30

    // Delete last remaining node
    clist.deleteAtHead();
    cout << "After deleting last node: ";
    clist.print();  // Expected: (no output)

    return 0;
}