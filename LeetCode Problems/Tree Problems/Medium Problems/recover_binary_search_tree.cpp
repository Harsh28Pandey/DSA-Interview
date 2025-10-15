// Problem - Recover Binary Search Tree (99) - LeetCode
// Time Complexity - O(n);
// Space Complexity - O(n)

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
    TreeNode *prev = NULL;
    TreeNode *first = NULL;
    TreeNode *second = NULL;

    void inorder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        if (prev != NULL && prev->val > root->val) {
            if (first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    Solution s;
    s.recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}