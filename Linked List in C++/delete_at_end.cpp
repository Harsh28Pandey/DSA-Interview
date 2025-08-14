#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node *CreateLinkedList(int arr[],int index,int size) {
    // base case
    if(index == size) 
    return NULL;

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr,index+1,size);
    return temp;
}

int main()
{
    Node *head;
    head = NULL;
    int arr[] = {2,3,4,6,8};
    head = CreateLinkedList(arr,0,5);

    // delete a node at last
    if(head != NULL) {
        // only one node is present
        if(head->next == NULL) {
            Node *temp = head;
            delete temp;
            head = NULL;
        }
        // more than one node is present
        else {
            Node *curr = head;
            Node *prev = NULL;
            while(curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
    }

    // print the values
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}