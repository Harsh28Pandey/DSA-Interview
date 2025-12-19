// Problem - Linked List Cycle II - (142) - LeetCode

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            isCycle = true;
            break;
        }
    }
    if(!isCycle) {
        return NULL;
    }
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    // Create nodes
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node0 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // Link nodes: 3 -> 2 -> 0 -> -4
    head->next = node2;
    node2->next = node0;
    node0->next = node4;

    // Create a cycle: -4 -> 2 (node2)
    node4->next = node2;

    // Detect cycle
    ListNode *cycleStart = detectCycle(head);

    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Note: memory cleanup is omitted here due to the cycle.
    return 0;
}