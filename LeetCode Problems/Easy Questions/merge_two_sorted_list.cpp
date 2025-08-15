// Problem - Merge Two Sorted List (21) - LeetCode

#include<iostream>
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to simplify edge cases
    ListNode dummy;
    ListNode* tail = &dummy;

    // Compare and attach smaller nodes one by one
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

    // Attach remaining nodes (only one of these will execute)
    if (list1) tail->next = list1;
    if (list2) tail->next = list2;

    return dummy.next; // Skip dummy and return actual head
}