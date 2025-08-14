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

class List {
    Node *head;
    Node *tail;
    public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return ;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertParticularPosition(int val, int pos) {
        if(pos < 0) {
            cout << "Invalid position" << endl;
            return ;
        }
        if(pos == 0) {
            push_front(val);
            return ;
        }
        Node *temp = head;
        for(int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = newNode;
        temp->next = newNode;
    }

    void printLinkedList() {
        Node *temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List l1;
    l1.insertParticularPosition(10, 0);
    l1.insertParticularPosition(20, 1);
    l1.insertParticularPosition(30, 2);
    l1.printLinkedList();
    return 0;
}