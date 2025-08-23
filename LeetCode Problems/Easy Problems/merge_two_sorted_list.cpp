// Problem - Merge Two Sorted List (21) - LeetCode

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) tail->next = list1;
    if (list2) tail->next = list2;

    return dummy.next;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    vector<int> vals1 = {1, 3, 5, 7};
    vector<int> vals2 = {2, 4, 6, 8};

    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList(vals2);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode* merged = mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printList(merged);

    // Clean up memory (optional here, but good practice)
    while (merged) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}
