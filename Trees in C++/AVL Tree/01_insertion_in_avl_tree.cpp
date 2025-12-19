// Time complexity - O(n * logn)

#include<iostream>
using namespace std;

class Node {
    public:
    int data,height;
    Node *left, *right;
    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root) {
    if(!root)
    return 0;

    return root->height;
}

int getBalance(Node *root) {
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotation(Node *root) {
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *leftRotation(Node *root) {
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *insert(Node *root, int key) {
    // doesn't exist
    if(!root)
    return new Node(key);

    // exist hai
    if(key < root->data) // left side
    root->left = insert(root->left, key);

    else if(key > root->data) // right side
    root->right = insert(root->right, key);

    else 
    return root; // duplicate element are not allowed

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // balancing check
    int balance = getBalance(root);

    // left left case
    if(balance > 1 && key < root->left->data)
    return rightRotation(root);

    // right right case
    else if(balance < -1 && root->right->data < key)
    return leftRotation(root);

    // left right case
    else if(balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // right left case 
    else if(balance < -1 && root->right->data > key) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    // no balancing
    else {
        return root;
    }
}

void preorder(Node *root) {
    if(!root) {
        return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if(!root) {
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); 
    root = insert(root,5);
    root = insert(root, 15);
    root = insert(root,100);
    root = insert(root,95);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder:";
    inorder(root);

    return 0;
}