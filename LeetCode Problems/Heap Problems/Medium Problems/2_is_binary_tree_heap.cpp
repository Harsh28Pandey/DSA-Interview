// Problem - IS Binary tree heap - gfg
// Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int count(Node *root) {
        if(!root)
            return 0;
        return 1 + count(root->left) + count(root->right);
    }
    
    bool CBT(Node *root, int index, int totalNodes) {
        if(!root)
            return true;
        
        if(index >= totalNodes)
            return false;
        
        return CBT(root->left, 2 * index + 1, totalNodes) && 
               CBT(root->right, 2 * index + 2, totalNodes);
    }
    
    bool maxHeap(Node *root) {
        if(root->left) {
            if(root->data < root->left->data)
                return false;
            
            if(!maxHeap(root->left))
                return false;
        }
        
        if(root->right) {
            if(root->data < root->right->data)
                return false;
            
            return maxHeap(root->right);
        }
        return true;
    }
  
    bool isHeap(Node* tree) {
        // count nodes in the tree
        int num = count(tree);
        
        // check if it's a complete binary tree
        if(!CBT(tree, 0, num))
            return false;
        
        // check heap property
        return maxHeap(tree);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    Solution sol;
    
    if(sol.isHeap(root))
        cout << "The given binary tree is a Max Heap.\n";
    else
        cout << "The given binary tree is NOT a Max Heap.\n";
    
    return 0;
}