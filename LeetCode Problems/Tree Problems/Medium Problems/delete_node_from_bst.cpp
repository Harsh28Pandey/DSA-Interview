// Problem - Delete a Node From BST - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)

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
    Node* delNode(Node* root, int x) {
        if(!root)
            return NULL;
        
        if(root->data > x) {
            root->left = delNode(root->left, x);
            return root;
        }
        
        else if(root->data < x) {
            root->right = delNode(root->right, x);
            return root;
        }
        
        else {
            if(!root->left && !root->right) { // leaf node
                delete root;
                return NULL;
            }
            
            else if(!root->right) { // only left child
                Node *temp = root->left;
                delete root;
                return temp;
            }
            
            else if(!root->left) { // only right child
                Node *temp = root->right;
                delete root;
                return temp;
            }
            
            else { // two children
                Node *child = root->left;
                Node *parent = root;
                
                while(child->right) {
                    parent = child;
                    child = child->right;
                }
                
                if(root != parent) {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                } else {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};

Node* insert(Node* root, int val) {
    if(!root) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    Node* root = NULL;
    int n, x;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;
    
    cout << "Enter node value to delete: ";
    cin >> x;
    
    root = sol.delNode(root, x);
    
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;
    
    return 0;
}