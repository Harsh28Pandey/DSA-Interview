// Problem - Convert sorted Linked List to BST (109) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildBST(vector<int> &Tree, int start, int end) {
        if (start > end)
            return NULL;
        
        int mid = start + (end - start + 1) / 2;
        TreeNode *root = new TreeNode(Tree[mid]);
        root->left = buildBST(Tree, start, mid - 1);
        root->right = buildBST(Tree, mid + 1, end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> Tree;
        while (head) {
            Tree.push_back(head->val);
            head = head->next;
        }
        return buildBST(Tree, 0, Tree.size() - 1);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> sortedVals = {-10, -3, 0, 5, 9};
    ListNode* head = createLinkedList(sortedVals);

    Solution obj;
    TreeNode* root = obj.sortedListToBST(head);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}