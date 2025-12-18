// Problem - Maximum Width of Binary Tree (662) - LeetCode
// Time Complexity - O(n)

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Define the tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int currLevelSize = q.size();
            unsigned long long startIndex = q.front().second;
            unsigned long long endIndex = q.back().second;

            maxWidth = max(maxWidth, (int)(endIndex - startIndex + 1));

            for (int i = 0; i < currLevelSize; i++) {
                auto curr = q.front();
                q.pop();

                unsigned long long idx = curr.second - startIndex;

                if (curr.first->left) {
                    q.push({curr.first->left, idx * 2 + 1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, idx * 2 + 2});
                }
            }
        }
        return maxWidth;
    }
};

int main() {
    // Build sample tree:
    //        1
    //       / \
    //      3   2
    //     /     \
    //    5       9
    //   /         \
    //  6           7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum width of binary tree: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}