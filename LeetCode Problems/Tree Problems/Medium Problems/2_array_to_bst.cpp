// Problem - Array to BST - gfg
// Time Complexity - O(n)

#include<iostream>
#include<vector>
#include<queue>
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
    Node* arrayToBST(vector<int> &arr, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        Node* root = new Node(arr[mid]);
        root->left = arrayToBST(arr, start, mid - 1);
        root->right = arrayToBST(arr, mid + 1, end);

        return root;
    }

    Node* sortedArrayToBST(vector<int>& arr) {
        return arrayToBST(arr, 0, arr.size() - 1);
    }
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl; // new line for each level
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Solution sol;
    Node* root = sol.sortedArrayToBST(arr);

    cout << "Inorder traversal (should be sorted): ";
    inorder(root);
    cout << "\n\nLevel order traversal (to visualize BST structure):\n";
    levelOrder(root);

    return 0;
}