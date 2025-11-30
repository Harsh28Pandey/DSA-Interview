// Problem - Linked List Cycle II (142) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                // cycle
                break;
            }
        }

        if(fast == NULL || fast->next == NULL) {
            return NULL;
        }

        ListNode *n1 = slow;
        ListNode *n2 = head;

        while(n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }
};