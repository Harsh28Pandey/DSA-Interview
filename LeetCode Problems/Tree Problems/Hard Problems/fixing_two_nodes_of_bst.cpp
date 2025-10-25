// Problem - Fixing Two Nodes of a BST - gfg

#include <iostream>
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
    void correctBST(Node* root) {
        Node *curr = NULL;
        Node *first = NULL, *second = NULL;
        Node *last = NULL, *present = NULL;
        
        while(root) {
            if(!root->left) {
                last = present;
                present = root;
                if(last && last->data > present->data) {
                    if(!first)
                        first = last;
                    second = present;
                }
                root = root->right;
            } 
            else {
                curr = root->left;
                while(curr->right && curr->right != root)
                    curr = curr->right;
                
                if(!curr->right) {
                    curr->right = root;
                    root = root->left;
                }
                else {
                    curr->right = NULL;
                    last = present;
                    present = root;
                    if(last && last->data > present->data) {
                        if(!first)
                            first = last;
                        second = present;
                    }
                    root = root->right;
                }
            }
        }
        if(first && second) {
            int num = first->data;
            first->data = second->data;
            second->data = num;
        }
    }
};

void printInorder(Node* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(1);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    root->right->right = new Node(10);

    cout << "Inorder before correction: ";
    printInorder(root);
    cout << endl;

    Solution s;
    s.correctBST(root);

    cout << "Inorder after correction: ";
    printInorder(root);
    cout << endl;

    return 0;
}