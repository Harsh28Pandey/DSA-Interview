// Problem - Construct Tree From Inorder and Preorder - gfg
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
    
    Node* buildTreeHelper(vector<int> &in, vector<int> &pre, int inStart, int inEnd, int &preIndex) {
        if (inStart > inEnd) 
        return NULL;

        Node* root = new Node(pre[preIndex++]);
        if (inStart == inEnd) 
        return root;

        int pos = find(in, root->data, inStart, inEnd);
        root->left = buildTreeHelper(in, pre, inStart, pos - 1, preIndex);
        root->right = buildTreeHelper(in, pre, pos + 1, inEnd, preIndex);
        return root;
    }
  
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int preIndex = 0;
        return buildTreeHelper(inorder, preorder, 0, n - 1, preIndex);
    }
};

void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    Solution obj;
    Node* root = obj.buildTree(inorder, preorder);
    printPostorder(root);
    return 0;
}