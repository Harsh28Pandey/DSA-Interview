#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
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
    ListNode *prev = NULL;
    while(slow != fast) {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev->next = NULL; // remove cycle
    return slow;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    int count = 0;
    while (curr != nullptr && count < 50) { // limit 50 to avoid infinite loop
        cout << curr->val << " -> ";
        curr = curr->next;
        count++;
    }
    if (curr != nullptr) {
        cout << "... (cycle detected)";
    } else {
        cout << "NULL";
    }
    cout << endl;
}

// Helper to create a cycle in the linked list at position pos (0-indexed)
void createCycle(ListNode* head, int pos) {
    if (pos < 0) return;
    ListNode* cycleStart = nullptr;
    ListNode* tail = head;
    int index = 0;
    while (tail->next != nullptr) {
        if (index == pos) {
            cycleStart = tail;
        }
        tail = tail->next;
        index++;
    }
    if (index == pos) {
        cycleStart = tail;
    }
    if (cycleStart != nullptr) {
        tail->next = cycleStart;
    }
}

int main() {
    // Create linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle at position 1 (node with value 2)
    createCycle(head, 1);

    cout << "List before cycle removal (limited print):" << endl;
    printList(head);

    ListNode* cycleNode = detectCycle(head);

    if (cycleNode != nullptr) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
        cout << "List after cycle removal:" << endl;
        printList(head);
    } else {
        cout << "No cycle detected." << endl;
    }

    // Cleanup nodes to prevent memory leaks (optional)
    // After removing cycle, it's safe to delete nodes sequentially
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}