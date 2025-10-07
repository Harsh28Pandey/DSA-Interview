// Time Complexity - O(n)

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val) {
    if(root == NULL) {
        return new Node(val);
    }
    if(val < root->data) {
        root->left = insert(root->left,val);
    }
    else {
        root->right = insert(root->right,val);
    }
    return root;
}

Node *buildBST(vector<int> arr) {
    Node *root = NULL;
    for(int val : arr) {
        root = insert(root,val);
    }
    return root;
}

void inorder(Node *root, vector<int> &arr) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

class Info {
    public:
    int min,max,size;
    Info(int mi, int mx, int sz) {
        min = mi;
        max = mx;
        size = sz;
    }
};

Info helper(Node *root) {
    if(root == NULL) {
        return Info(INT_MAX, INT_MIN, 0);
    }
    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min) {
        int currMin = min(root->data,left.min);
        int currMax = max(root->data,right.max);
        int currSize = left.size + right.size + 1;
        return Info(currMin, currMax, currSize);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBSTInBT(Node *root) {
    Info info = helper(root);
    return info.size; // max BST Size
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(50);

    cout << largestBSTInBT(root) << endl;
    return 0;
}