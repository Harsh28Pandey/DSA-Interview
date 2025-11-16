// Problem - Lowest Common Ancestor of a Binary Tree III - NeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // Use a set of pointers (Node*)
        unordered_set<Node*> visited;

        // Move upward from p and store ancestors
        while (p != nullptr) {
            visited.insert(p);
            p = p->parent;   // use -> for pointer access
        }

        // Move upward from q and find first common ancestor
        while (q != nullptr) {
            if (visited.count(q)) {   // check if exists in set
                return q;
            }
            q = q->parent;
        }

        return nullptr;   // no LCA found
    }
};


// Optimized Approach
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *p1 = p;
        Node *q1 = q;

        while(p1 != q1) {
            p1 = (p1 == nullptr) ? q : p1->parent;
            q1 = (q1 == nullptr) ? p : q1->parent;
        }
        return p1;
    }
};