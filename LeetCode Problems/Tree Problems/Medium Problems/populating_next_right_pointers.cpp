// Problem - Populating Next Right Pointers in each Node (116) - LeetCode
// Time Complexity - O(n)

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL) {
            return root;
        }
        queue<Node *> q;
        q.push(root);
        q.push(NULL); // mark the end of a level
        Node *prev = NULL;

        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();
            if(curr == NULL) {
                if(q.empty()) break;
                q.push(NULL);
            } else {
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                if(prev != NULL) prev->next = curr;
            }
            prev = curr;
        }
        return root;
    }
};

void printLevels(Node* root) {
    Node* levelStart = root;
    while (levelStart != NULL) {
        Node* curr = levelStart;
        levelStart = levelStart->left;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "# "; // end of level
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    root = sol.connect(root);

    // Print using next pointers
    printLevels(root);

    return 0;
}