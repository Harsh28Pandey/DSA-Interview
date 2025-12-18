// Problem - Diagonal Traversal of Bimary Tree - gfg

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    void find(Node *root, int pos, int &l) {
        if (!root)
            return;
        l = max(pos, l);
        find(root->left, pos + 1, l);
        find(root->right, pos, l);
    }

    void findDiagonal(Node *root, int pos, vector<vector<int>> &ans) {
        if (!root)
            return;
        ans[pos].push_back(root->data);
        findDiagonal(root->left, pos + 1, ans);
        findDiagonal(root->right, pos, ans);
    }

    vector<int> diagonal(Node *root) {
        int l = 0;
        find(root, 0, l);
        vector<vector<int>> ans(l + 1);
        findDiagonal(root, 0, ans);
        vector<int> temp;

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                temp.push_back(ans[i][j]);
            }
        }
        return temp;
    }
};

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Solution sol;
    vector<int> result = sol.diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}