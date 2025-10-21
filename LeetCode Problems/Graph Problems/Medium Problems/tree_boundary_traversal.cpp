// Problem - Tree Boundary Traversal - gfg

#include<iostream>
#include<vector>
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
    void leftSub(Node *root, vector<int> &ans) {
        if(!root || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        if(root->left) leftSub(root->left, ans);
        else leftSub(root->right, ans);
    }

    void leaf(Node *root, vector<int> &ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        leaf(root->left, ans);
        leaf(root->right, ans);
    }

    void rightSub(Node *root, vector<int> &ans) {
        if(!root || (!root->left && !root->right)) return;
        if(root->right) rightSub(root->right, ans);
        else rightSub(root->left, ans);
        ans.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        ans.push_back(root->data); // root

        // Left boundary (excluding leaf)
        leftSub(root->left, ans);

        // Leaf nodes
        if(root->left || root->right)
            leaf(root, ans);

        // Right boundary (in reverse)
        rightSub(root->right, ans);

        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}