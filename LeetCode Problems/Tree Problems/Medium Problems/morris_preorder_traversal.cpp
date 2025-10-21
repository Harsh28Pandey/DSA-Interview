// Problem - Preorder Traversal (Iterative) - gfg

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        while (root) {
            // left part doesn't exist
            if (!root->left) {
                ans.push_back(root->data);
                root = root->right;
            }
            // left part exists
            else {
                Node* curr = root->left;
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }
                // left subtree not traversed
                if (curr->right == NULL) {
                    ans.push_back(root->data);
                    curr->right = root;
                    root = root->left;
                }
                // already traversed
                else {
                    curr->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Create object of Solution and call preOrder
    Solution sol;
    vector<int> res = sol.preOrder(root);

    // Print preorder traversal
    cout << "Preorder traversal: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}