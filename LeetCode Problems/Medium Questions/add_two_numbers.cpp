// Problem - Add Two Numbers (2) - LeetCode

#include<iostream>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); // Dummy head node for easier handling
    ListNode* current = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10; // carry for next step
        sum = sum % 10;   // current digit value
        
        current->next = new ListNode(sum);
        current = current->next;
    }

    return dummy.next; // skip dummy head
}