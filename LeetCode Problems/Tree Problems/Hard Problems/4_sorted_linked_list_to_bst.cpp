// Problem - Sorted Linked List to BST - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
using namespace std;

struct LNode {
    int data;
    LNode *next;
    LNode(int val) : data(val), next(NULL) {}
};

struct TNode {
    int data;
    TNode *left;
    TNode *right;
    TNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TNode *buildBST(vector<int> &Tree, int start, int end) {
        if (start > end)
            return NULL;
        
        int mid = start + (end - start + 1) / 2;
        TNode *root = new TNode(Tree[mid]);
        root->left = buildBST(Tree, start, mid - 1);
        root->right = buildBST(Tree, mid + 1, end);
        return root;
    }
  
    TNode *sortedListToBST(LNode *head) {
        vector<int> Tree;
        while (head) {
            Tree.push_back(head->data);
            head = head->next;
        }
        return buildBST(Tree, 0, Tree.size() - 1);
    }
};

void inorder(TNode *root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

LNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    LNode* head = new LNode(vals[0]);
    LNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new LNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> sortedVals = {-10, -3, 0, 5, 9};
    LNode* head = createLinkedList(sortedVals);

    Solution obj;
    TNode* root = obj.sortedListToBST(head);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}