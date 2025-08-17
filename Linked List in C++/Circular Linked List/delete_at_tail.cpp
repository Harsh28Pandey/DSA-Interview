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

    void deleteAtTail() {
        if(head == NULL) {
            return ;
        }
        else if(head == tail) { // single node
            delete head;
            head = tail = NULL;
        }
        else { // two or more node
            Node *temp = tail;
            Node *prev = head;
            while(prev->next != tail) {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
};

int main() {
    circularList clist;

    // Insert some nodes
    clist.insertAtTail(10);
    clist.insertAtTail(20);
    clist.insertAtTail(30);
    clist.insertAtTail(40);

    cout << "Original list: ";
    clist.print();  // Expected: 10->20->30->40->10

    // Delete tail node
    clist.deleteAtTail();
    cout << "After deleting tail: ";
    clist.print();  // Expected: 10->20->30->10

    // Delete tail again
    clist.deleteAtTail();
    cout << "After deleting tail again: ";
    clist.print();  // Expected: 10->20->10

    // Delete tail until empty
    clist.deleteAtTail();
    cout << "After deleting tail third time: ";
    clist.print();  // Expected: 10->10

    clist.deleteAtTail();
    cout << "After deleting tail fourth time (should be empty): ";
    clist.print();  // Expected: no output

    return 0;
}