// Problem - Kth Largest Element in BST - gfg

#include<iostream>
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
    void kLargest(Node *root, int &ans, int &k) {
        if (!root)
            return;
        kLargest(root->right, ans, k); // Traverse right subtree first
        k--;
        if (k == 0)
            ans = root->data;          // Found kth largest
        if (k <= 0)
            return;
        kLargest(root->left, ans, k);  // Then left subtree
    }

    int kthLargest(Node *root, int k) {
        int ans = -1;
        kLargest(root, ans, k);
        return ans;
    }
};

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    int result = sol.kthLargest(root, k);

    if (result != -1)
        cout << "The " << k << "th largest element is: " << result << endl;
    else
        cout << "Invalid input. Tree has fewer than " << k << " nodes." << endl;

    return 0;
}