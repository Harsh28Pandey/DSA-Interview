// Problem - Sum of K Smallest Element in BST - gfg

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

void kSum(Node *root, int &sum, int &k) {
    if (!root)
        return;
    kSum(root->left, sum, k);
    k--;
    if (k >= 0)
        sum += root->data;
    if (k <= 0)
        return;
    kSum(root->right, sum, k);
}

int sum(Node* root, int k) {
    int sumVal = 0;
    kSum(root, sumVal, k);
    return sumVal;
}

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

    int result = sum(root, k);
    cout << "Sum of first " << k << " smallest elements = " << result << endl;

    return 0;
}