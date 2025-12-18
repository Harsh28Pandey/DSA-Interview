// Problem - find Common Nodes in Two BSTs - gfg

#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> findCommon(Node *root1, Node *root2) {
        vector<int> ans;
        stack<Node *> s1, s2;
        while(root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        while(root2) {
            s2.push(root2);
            root2 = root2->left;
        }
        while(!s1.empty() && !s2.empty()) {
            if(s1.top()->data == s2.top()->data) {
                ans.push_back(s1.top()->data);
                root1 = s1.top()->right;
                s1.pop();
                root2 = s2.top()->right;
                s2.pop();
            }
            else if(s1.top()->data > s2.top()->data) {
                root2 = s2.top()->right;
                s2.pop();
            }
            else {
                root1 = s1.top()->right;
                s1.pop();
            }
            while(root1) {
                s1.push(root1);
                root1 = root1->left;
            }
            while(root2) {
                s2.push(root2);
                root2 = root2->left;
            }
        }
        return ans;
    }
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    Node* root1 = nullptr;
    Node* root2 = nullptr;

    // BST 1
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1, 0);
    root1 = insert(root1, 4);
    root1 = insert(root1, 7);
    root1 = insert(root1, 9);

    // BST 2
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);

    Solution obj;
    vector<int> commonNodes = obj.findCommon(root1, root2);

    cout << "Common nodes in both BSTs are: ";
    printVector(commonNodes);

    return 0;
}