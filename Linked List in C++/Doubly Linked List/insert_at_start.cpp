#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *head = NULL;

    // insert at start
    // linked list doesn't exist
    if(head == NULL) {
        head = new Node(5);
    }

    // linked list already exist
    else {
        Node *temp = new Node(5);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    // print the values
    Node *trav = head;
    while(trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}