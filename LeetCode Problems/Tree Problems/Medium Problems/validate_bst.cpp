// Problem - Validate Binary Search Tree (98) - LeetCode
// Time Complexity - O(n)

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Your Solution class
class Solution {
public:
    bool helper(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (root == NULL) {
            return true;
        }
        if (min != NULL && root->val <= min->val) {
            return false;
        }
        if (max != NULL && root->val >= max->val) {
            return false;
        }
        return helper(root->left, min, root) && helper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};

int main() {
    // Create a valid BST
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution s;
    if (s.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    TreeNode* invalidRoot = new TreeNode(5);
    invalidRoot->left = new TreeNode(1);
    invalidRoot->right = new TreeNode(4);
    invalidRoot->right->left = new TreeNode(3);
    invalidRoot->right->right = new TreeNode(6);

    if (s.isValidBST(invalidRoot)) {
        cout << "The second tree is a valid BST." << endl;
    } else {
        cout << "The second tree is NOT a valid BST." << endl;
    }

    return 0;
}