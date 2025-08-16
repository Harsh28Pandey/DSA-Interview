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
    // insert at end    
    Node *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    Node *temp = new Node(5);
    curr->next = temp;
    temp->prev = curr;

    // print the values
    Node *trav = head;
    while(trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}