// Problem - Lowest Common Ancestor of a Binary Search Tree (235) - LeetCode
// Time Complexity - O(log n)

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

int main() {
    // Construct the following BST:
    //         6
    //        / \
    //       2   8
    //      / \ / \
    //     0  4 7  9
    //       / \
    //      3   5

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution sol;
    TreeNode* p = root->left;         // Node 2
    TreeNode* q = root->left->right;  // Node 4

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "No common ancestor found." << endl;

    return 0;
}