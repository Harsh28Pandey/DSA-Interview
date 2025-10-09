// Problem - Convert Sorted Array to Binary Search Tree (108) - LeetCode
// Time Complexity - O(n)

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

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Function to print inorder traversal of BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}