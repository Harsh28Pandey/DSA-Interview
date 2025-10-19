// Problem - Vertical Tree Traversal - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void find(Node *root, int pos, int &l, int &r) {
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }
  
    vector<vector<int>> verticalOrder(Node *root) {
        if (!root) return {};
        
        int l = 0, r = 0;
        find(root, 0, l, r);
        
        vector<vector<int>> Positive(r + 1); // right side (including root)
        vector<vector<int>> Negative(abs(l) + 1); // left side
        
        queue<Node*> q;
        queue<int> index;
        
        q.push(root);
        index.push(0);
        
        while(!q.empty()) {
            Node *temp = q.front(); q.pop();
            int pos = index.front(); index.pop();
            
            if (pos >= 0)
                Positive[pos].push_back(temp->data);
            else
                Negative[abs(pos)].push_back(temp->data);
            
            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }
        
        vector<vector<int>> ans;
        
        // add negative part (from leftmost to root)
        for (int i = Negative.size() - 1; i > 0; i--) {
            ans.push_back(Negative[i]);
        }
        
        // add root and right side
        for (int i = 0; i < Positive.size(); i++) {
            ans.push_back(Positive[i]);
        }
        
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->right = new Node(8);

    Solution obj;
    vector<vector<int>> result = obj.verticalOrder(root);

    cout << "Vertical Order Traversal:\n";
    for (auto &col : result) {
        for (int val : col)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}