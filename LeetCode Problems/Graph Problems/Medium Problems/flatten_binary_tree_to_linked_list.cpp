// Problem - Flatten Binary Tree to Linked List

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void flatten(Node *root) {
        while(root) {
            if(!root->left) {
                root = root->right;
            } else {
                Node *curr = root->left;
                while(curr->right) {
                    curr = curr->right;
                }
                curr->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};

void printFlattened(Node* root) {
    while(root) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    
    Solution sol;
    sol.flatten(root);
    
    cout << "Flattened tree (as linked list): ";
    printFlattened(root);
    
    return 0;
}