// create a doubly linked list using recursion

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

Node *CreateDLL(int arr[],int index,int size,Node *back) {
    if(index == size) {
        return NULL;
    }

    // node create karo
    Node *temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = CreateDLL(arr,index+1,size,temp);
    return temp;
}

int main()
{
    Node *head = NULL;
    // create doubly linked list
    int arr[] = {1,2,3,4,5};

    // create using recursion
    head = CreateDLL(arr,0,5,NULL);

    // print the values
    Node *trav = head;
    while(trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}