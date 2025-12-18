// Problem - Kth Smallest Element in a BST (230) - LeetCode
// Time Complecity - O(n)

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int prevOrder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }

        if (root->left != NULL) {
            int leftAns = kthSmallest(root->left, k);
            if (leftAns != -1) {
                return leftAns;
            }
        }

        if (prevOrder + 1 == k) {
            return root->val;
        }
        prevOrder = prevOrder + 1;

        if (root->right != NULL) {
            int rightAns = kthSmallest(root->right, k);
            if (rightAns != -1) {
                return rightAns;
            }
        }

        return -1;
    }
};

TreeNode* buildSampleTree() {
    /*
            5
           / \
          3   7
         / \ / \
        2  4 6  8
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;

    int k;
    cout << "Enter k: ";
    cin >> k;

    int result = sol.kthSmallest(root, k);
    if (result == -1) {
        cout << "k is out of range." << endl;
    } else {
        cout << "The " << k << "th smallest element is: " << result << endl;
    }
    return 0;
}