// Problem - Check For BST - gfg
// Time Complexity - O(n)
// Space Complexity - O(1)

#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    bool BST(Node *root, int &prev) {
        if (!root)
            return true;
        if (!BST(root->left, prev))
            return false;
        if (root->data <= prev)
            return false;
        prev = root->data;
        return BST(root->right, prev);
    }

    bool isBST(Node* root) {
        int prev = INT_MIN;
        return BST(root, prev);
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Solution sol;
    if (sol.isBST(root))
        cout << "The tree is a BST." << endl;
    else
        cout << "The tree is NOT a BST." << endl;

    Node* badRoot = new Node(10);
    badRoot->left = new Node(5);
    badRoot->right = new Node(8);

    if (sol.isBST(badRoot))
        cout << "The second tree is a BST." << endl;
    else
        cout << "The second tree is NOT a BST." << endl;

    return 0;
}