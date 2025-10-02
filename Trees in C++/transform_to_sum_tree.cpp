// Time Complexity - O(n)

#include<iostream>
#include<vector>
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

static int index = -1;
Node *buildTree(vector<int> preOrder) {
    index++;
    if(preOrder[index] == -1) {
        return NULL;
    }
    Node *root = new Node(preOrder[index]);
    root->left = buildTree(preOrder); // left
    root->right = buildTree(preOrder); // right
    return root;
}

void preOrderTraversal(Node *root) {
    if(root == NULL) {
        return ;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int sumTree(Node *root) {
    if(root == NULL) {
        return 0;
    }
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data += leftSum + rightSum;
    return root->data;
}

int main() {
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root = buildTree(preOrder);
    cout << "Before Conversion: ";
    preOrderTraversal(root);
    cout << endl;

    sumTree(root);

    cout << "After Conversion: ";
    preOrderTraversal(root);
    cout << endl;
    return 0;
}