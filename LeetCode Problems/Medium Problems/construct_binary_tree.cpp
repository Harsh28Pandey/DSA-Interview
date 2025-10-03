// Problem - Conatruct Binary tree From Preorder and inorder Traversal (105) - LeetCode

#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition (needed for your Solution class)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int search(vector<int> &inorder,int left, int right, int value) {
        for(int i = left; i <= right; i++) {
            if(inorder[i] == value) {
                return i;
            }
        }
        return -1;
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int left, int right) {
        if(left > right) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preorderIndex]);
        int inorderIndex = search(inorder,left,right,preorder[preorderIndex]);
        preorderIndex++;

        root->left = helper(preorder,inorder,preorderIndex,left,inorderIndex - 1);
        root->right = helper(preorder,inorder,preorderIndex,inorderIndex + 1,right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        return helper(preorder,inorder,preorderIndex,0,inorder.size() - 1);
    }
};

// Helper to print inorder traversal (to verify correctness)
void printInorder(TreeNode* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    // Example input
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder  = {9,3,15,20,7};

    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}