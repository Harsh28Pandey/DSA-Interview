// Problem - Binary Tree Inorder Traversal (94) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr = root;

        while(curr != NULL) {
            if(curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode *IP = curr->left;
                while(IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }
                if(IP->right == NULL) {
                    IP->right = curr; // create
                    curr = curr->left;
                }
                else {
                    IP->right = NULL; // destroy
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Construct a sample binary tree:
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}