// Problem - Palindrome Linked List (234) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    ListNode* reverseLinkedList(ListNode *head) {
        ListNode *prev = NULL;

        while(head != NULL) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *p2 = reverseLinkedList(slow);
        ListNode *p1 = head;

        while(p1 != NULL && p2 != NULL) {
            if(p1->val != p2->val) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};