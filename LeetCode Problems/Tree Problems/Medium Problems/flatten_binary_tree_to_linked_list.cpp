// Problem - Flatten Binary Tree to Linked List (114) - LeetCode
// Time Complexity - O(n)

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Your Solution class
class Solution {
public:
    TreeNode *nextRight = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};

// Helper function to print the flattened tree
void printFlattened(TreeNode* root) {
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Construct a sample binary tree:
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree (preorder as linked list): ";
    printFlattened(root);

    // Cleanup (optional, since program ends)
    return 0;
}