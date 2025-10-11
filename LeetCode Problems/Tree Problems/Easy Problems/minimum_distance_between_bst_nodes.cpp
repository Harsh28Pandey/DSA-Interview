// Problem - Minimum Distance Between BST Nodes (783) - LeetCode
// Time Complexity: O(n)

#include <iostream>
#include <climits>
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
    int minDiffInBST(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;
        }
        int ans = INT_MAX;
        if (root->left != NULL) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        if (root->right != NULL) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }
        return ans;
    }
};

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int result = sol.minDiffInBST(root);
    cout << "Minimum difference in BST: " << result << endl;
    return 0;
}