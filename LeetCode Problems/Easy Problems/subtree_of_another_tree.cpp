// Problem - Subtree of Another Tree (572) - LeetCode

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isIdentical(TreeNode *p, TreeNode *q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }
        return p->val == q->val
            && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL) {
            return root == subRoot;
        }
        if(root->val == subRoot->val && isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// Helper function to print tree (preorder traversal)
void printTree(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Build root tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Build subRoot tree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;

    cout << "SubRoot (Preorder Traversal): ";
    printTree(subRoot);
    cout << endl;

    if(sol.isSubtree(root, subRoot)) {
        cout << "subRoot is a subtree of root." << endl;
    } else {
        cout << "subRoot is NOT a subtree of root." << endl;
    }

    return 0;
}
