// Problem - Maximum Path Sum Between Two Special Nodes - gfg

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
    int pathSum(Node *root, int &sum) {
        if (!root)
            return 0;

        // leaf node
        if (!root->left && !root->right)
            return root->data;

        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);

        // left and right both exist
        if (root->left && root->right) {
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        }

        // only left exist
        if (root->left) {
            return root->data + left;
        }

        // only right exist
        return root->data + right;
    }

    int maxPathSum(Node *root) {
        int sum = INT_MIN;
        int val = pathSum(root, sum);
        if (root->left && root->right) {
            return sum;
        }
        return max(sum, val);
    }
};

int main() {
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution obj;
    cout << "Maximum Path Sum: " << obj.maxPathSum(root) << endl;

    return 0;
}