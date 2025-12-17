// Time Complexity - O(log n)

#include <iostream>
using namespace std;

class Node {
public:
    int data, height;
    Node *left, *right;
    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root) {
    if (!root) return 0;
    return root->height;
}

int getBalance(Node *root) {
    if (!root) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotation(Node *root) {
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *leftRotation(Node *root) {
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *insertNode(Node *root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);
    else
        return root; // no duplicates

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < root->left->data)
        return rightRotation(root);

    // RR
    if (balance < -1 && key > root->right->data)
        return leftRotation(root);

    // LR
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RL
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

Node *deleteNode(Node *root, int key) {
    if (!root)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // leaf node
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // only left child
        else if (root->left && !root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // only right child
        else if (!root->left && root->right) {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // both children
        else {
            Node *curr = root->right;
            while (curr->left) curr = curr->left;
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotation(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotation(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;

    // Insert nodes
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Delete a node
    root = deleteNode(root, 40);

    cout << "Inorder after deleting 40: ";
    inorder(root);
    cout << endl;

    return 0;
}