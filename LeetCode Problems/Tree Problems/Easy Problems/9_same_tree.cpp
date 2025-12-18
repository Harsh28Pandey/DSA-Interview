// Problem - Same Tree (100) - LeetCode
// Time Complexity - O(n);

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);
        return isLeftSame && isRightSame && p->val == q->val;
    }
};

int main() {
    // Build first tree
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Build second tree
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    if (sol.isSameTree(p, q)) {
        cout << "Trees are the same." << endl;
    } else {
        cout << "Trees are different." << endl;
    }

    // Cleanup memory
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}
