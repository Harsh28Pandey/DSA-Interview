// Problem - Copy List with Random Pointer (138) - LeetCode

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node *copyRandom(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    unordered_map<Node*, Node*> m;
    Node *newHead = new Node(head->val);
    Node *oldTemp = head->next;
    Node *newTemp = newHead;
    m[head] = newHead;

    while(oldTemp != NULL) {
        Node *copyNode = new Node(oldTemp->val);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    oldTemp = head, newTemp = newHead;
    while(oldTemp != NULL) {
        newTemp->random = m[oldTemp->random];
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }
    return newHead;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node value: " << temp->val;
        if (temp->random)
            cout << ", Random points to: " << temp->random->val;
        else
            cout << ", Random points to: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Create nodes
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    // Connect next pointers
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Set random pointers
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    // Deep copy the list
    Node* copiedHead = copyRandom(node1);

    cout << "Original list:\n";
    printList(node1);

    cout << "\nCopied list:\n";
    printList(copiedHead);

    return 0;
}