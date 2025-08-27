// Problem - Swap Nodes in Pairs (24) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *prev = NULL;

    while(first != NULL && second != NULL) {
        ListNode *third = second->next;
        second->next = first;
        first->next = third;
        if(prev != NULL) {
            prev->next = second;
        } else {
            head = second;
        }

        prev = first;
        first = third;
        if(third != NULL) {
            second = third->next;
        } else {
            second = NULL;
        }
    }
    return head;
}

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: create list 1->2->3->4
    vector<int> values = {1, 2, 3, 4};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    head = swapPairs(head);

    cout << "After swapping pairs: ";
    printList(head);

    return 0;
}