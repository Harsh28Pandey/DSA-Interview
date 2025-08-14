// Problem - Middle of the Linked List (876) - LeetCode

#include<iostream>
using namespace std;

ListNode middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}