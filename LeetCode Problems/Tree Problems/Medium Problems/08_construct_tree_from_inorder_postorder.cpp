// Problem - Tree From Postorder and Inorder - gfg
// Time Complexity - O(n * n)
// Space Complexity - O(n)

#include<iostream>
#include<vector>
#include<climits>
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
    int find(vector<int> &in, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == target) return i;
        }
        return -1;
    }
    
    Node* buildTreeHelper(vector<int> &in, vector<int> &post, int inStart, int inEnd, int &postIndex) {
        if (inStart > inEnd) return NULL;
        Node* root = new Node(post[postIndex--]);
        if (inStart == inEnd) return root;
        int pos = find(in, root->data, inStart, inEnd);
        root->right = buildTreeHelper(in, post, pos + 1, inEnd, postIndex);
        root->left = buildTreeHelper(in, post, inStart, pos - 1, postIndex);
        return root;
    }
  
    Node* buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int postIndex = n - 1;
        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }
};

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};
    Solution obj;
    Node* root = obj.buildTree(inorder, postorder);
    printPreorder(root);
    return 0;
}