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

    void insertAtHead(int val) {
        Node *newNode = new Node(val);
        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
};

int main() {
    circularList clist;

    // Insert some values at the head
    clist.insertAtHead(10);
    clist.insertAtHead(20);
    clist.insertAtHead(30);

    // Print the circular linked list
    clist.print();  // Expected output: 30->20->10->30

    return 0;
}