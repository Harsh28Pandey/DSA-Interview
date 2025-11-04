// Problem - IS Binary tree heap - gfg
// Time Complexity: O(n)

#include <bits/stdc++.h>
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
    void inorder(Node *root, vector<int> &ans) {
        if(!root)
            return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    void postorder(Node *root, vector<int> &ans, int &index) {
        if(!root)
            return;
        
        postorder(root->left, ans, index);
        postorder(root->right, ans, index);
        root->data = ans[index++];
    }
  
    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;
        inorder(root, ans); // store inorder traversal (sorted order for BST)
        int index = 0;
        postorder(root, ans, index); // assign values in postorder to form Max Heap
    }
};

void printPostorder(Node* root) {
    if (!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void printInorder(Node* root) {
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    
    Solution sol;
    
    cout << "Inorder of original BST: ";
    printInorder(root);
    cout << "\n";
    
    sol.convertToMaxHeapUtil(root);
    
    cout << "Postorder of converted Max Heap: ";
    printPostorder(root);
    cout << "\n";
    
    return 0;
}