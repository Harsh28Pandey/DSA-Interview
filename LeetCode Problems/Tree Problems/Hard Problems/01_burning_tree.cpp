// Problem - Burning Tree gfg
// Time Complexity - O(n)

#include<iostream>
#include<climits>
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
    int burn(Node *root, int &timer, int target) {
        if (!root) // if not exist
            return 0;

        if (root->data == target) // if target found
            return -1;

        int left = burn(root->left, timer, target);
        int right = burn(root->right, timer, target);

        // burn condition
        if (left < 0) {
            timer = max(timer, abs(left) + right);
            return left - 1;
        }

        if (right < 0) {
            timer = max(timer, left + abs(right));
            return right - 1;
        }

        // return height
        return 1 + max(left, right);
    }

    void find(Node *root, int target, Node *&burnNode) {
        if (!root)
            return;

        if (root->data == target) {
            burnNode = root;
            return;
        }

        find(root->left, target, burnNode);
        find(root->right, target, burnNode);
    }

    int height(Node *root) {
        if (!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int minTime(Node *root, int target) {
        int timer = 0;
        burn(root, timer, target);

        // find target node
        Node *burnNode = nullptr;
        find(root, target, burnNode);

        int high = height(burnNode) - 1; // height of target subtree
        return max(timer, high);
    }
};

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    Solution obj;

    int target = 5;
    cout << "Minimum time to burn the tree from target " << target << " is: "
         << obj.minTime(root, target) << " seconds." << endl;

    return 0;
}