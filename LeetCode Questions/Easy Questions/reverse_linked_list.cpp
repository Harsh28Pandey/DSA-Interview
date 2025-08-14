// Problem - Reverse Linked List (206) - LeetCode

#include<iostream>
using namespace std;

ListNode *reverseList(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}