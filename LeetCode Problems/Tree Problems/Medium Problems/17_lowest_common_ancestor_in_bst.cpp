// Problem - Lowest Common Ancestor in BST - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
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
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (root == NULL) 
            return NULL;

        if (root->data > n1->data && root->data > n2->data)
            return LCA(root->left, n1, n2);

        if (root->data < n1->data && root->data < n2->data)
            return LCA(root->right, n1, n2);

        return root;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node* find(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return find(root->left, key);
    return find(root->right, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    Solution obj;

    Node* n1 = find(root, 10);
    Node* n2 = find(root, 14);

    Node* lca = obj.LCA(root, n1, n2);

    if (lca)
        cout << "LCA of " << n1->data << " and " << n2->data << " is " << lca->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}