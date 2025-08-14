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
    if(index == size) {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr,index+1,size);
    return temp;
}

int main()
{
    Node *head;
    head = NULL;
    int arr[] = {2,4,6,8,10};

    head = CreateLinkedList(arr,0,5);
    Node *temp;
    temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}