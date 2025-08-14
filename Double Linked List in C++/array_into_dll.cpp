// convert array into doubly linked list

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
    Node *head, *tail;
    int arr[] = {2,4,6,8,10};
    head = tail = NULL;
    for(int i = 0; i < 5; i++) {
        if(head == NULL) {
            head = new Node(arr[i]);
            tail = head;
        }
        else {
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    // print the values
    Node *trav = head;
    while(trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}