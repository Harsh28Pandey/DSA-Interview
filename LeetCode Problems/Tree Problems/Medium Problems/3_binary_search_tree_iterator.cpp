// Problem - Binary Search Tree Iterator (173) - LeetCode
// Time Complexity - O(1) - Constant
// Space Complexity - O(h) - Height of the tree

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode *> s;

    void storeLeftNodes(TreeNode *root) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode *ans = s.top();
        s.pop();
        storeLeftNodes(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

TreeNode* createSampleBST() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    return root;
}

// Main function
int main() {
    TreeNode* root = createSampleBST();
    BSTIterator iterator(root);

    cout << "BST elements in sorted order: ";
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}