// Problem - Linked List Cycle (141) - LeetCode

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    // Create nodes
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Connect nodes: 3 -> 2 -> 0 -> -4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create cycle: -4 points back to node2
    node4->next = node2;

    if(hasCycle(node1)) {
        cout << "Cycle detected in the linked list.\n";
    } else {
        cout << "No cycle in the linked list.\n";
    }

    // Important: Since there's a cycle, normal deletion would loop infinitely.
    // For demo purpose, we skip deletion here.

    return 0;
}