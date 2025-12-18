// Problem - Inorder Traversal (Iterative) / Iterative Inorder - gfg

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        while (root) {
            if (!root->left) {
                ans.push_back(root->data);
                root = root->right;
            } else {
                Node* curr = root->left;
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }

                if (curr->right == nullptr) {
                    curr->right = root;
                    root = root->left;
                } else {
                    curr->right = nullptr;
                    ans.push_back(root->data);
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

    // Create solution object
    Solution sol;
    vector<int> result = sol.inOrder(root);

    // Print inorder traversal
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}