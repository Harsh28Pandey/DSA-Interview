// Problem - Flatten a Multilevel Doubly Linked List (430) - LeetCode

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(NULL), next(NULL), child(NULL) {}
};

Node* flatten(Node* head) {
    if(head == NULL) {
        return head;
    }
    Node *curr = head;
    while(curr != NULL) {
        if(curr->child != NULL) {
            // flatten the child nodes
            Node *next = curr->next;
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;

            // find tail node
            while(curr->next != NULL) {
                curr = curr->next;
            }

            // attach tail with next pointer
            if(next != NULL) {
                curr->next = next;
                next->prev = curr;
            }
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    // Create a child list for node 2
    Node* child1 = new Node(5);
    child1->next = new Node(6);
    child1->next->prev = child1;
    head->next->child = child1;

    // Flatten and print
    Node* flattened = flatten(head);
    cout << "Flattened list: ";
    printList(flattened);

    return 0;
}