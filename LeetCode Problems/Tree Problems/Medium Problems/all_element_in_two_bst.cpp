// Problem - All Elements in Two Binary Search Trees (1305) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode *root, vector<int> &ans) {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);
        vector<int> ans;
        int i = 0, j = 0;

        while (i < ans1.size() && j < ans2.size()) {
            if (ans1[i] < ans2[j])
                ans.push_back(ans1[i++]);
            else
                ans.push_back(ans2[j++]);
        }

        while (i < ans1.size())
            ans.push_back(ans1[i++]);

        while (j < ans2.size())
            ans.push_back(ans2[j++]);

        return ans;
    }
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

TreeNode* buildBST(const vector<int>& vals) {
    TreeNode* root = NULL;
    for (int v : vals)
        root = insertBST(root, v);
    return root;
}

int main() {
    vector<int> vals1 = {2, 1, 4};   // Tree 1
    vector<int> vals2 = {1, 0, 3};   // Tree 2

    TreeNode* root1 = buildBST(vals1);
    TreeNode* root2 = buildBST(vals2);

    Solution sol;
    vector<int> result = sol.getAllElements(root1, root2);

    cout << "Merged sorted elements: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}