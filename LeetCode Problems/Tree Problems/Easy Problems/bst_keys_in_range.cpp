// Problem - BST Keys in a Range - gfg

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int n1, n2;
    void find(Node *root, vector<int> &ans) {
        if (!root)
            return;
        if (root->data > n1 && root->data > n2)
            find(root->left, ans);
        else if (root->data < n1 && root->data < n2)
            find(root->right, ans);
        else {
            find(root->left, ans);
            if (root->data >= n1 && root->data <= n2)
                ans.push_back(root->data);
            find(root->right, ans);
        }
    }

    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        n1 = low, n2 = high;
        find(root, ans);
        return ans;
    }
};

Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int main() {
    Node* root = nullptr;
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int val : values)
        root = insert(root, val);

    int low = 5, high = 13;

    Solution obj;
    vector<int> result = obj.printNearNodes(root, low, high);

    cout << "Nodes between " << low << " and " << high << ": ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}