// Problem - Remove Nth Node From End of List (19) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int length = 0;
        ListNode *l = head;

        while(l != NULL) {
            length = length + 1;
            l = l->next;
        }

        int d = length - n + 1;
        ListNode *prev = dummy;
        ListNode *curr = head;

        int i = 0;
        while(i < (d - 1)) {
            curr = curr->next;
            prev = prev->next;
            i = i + 1;
        }
        prev->next = prev->next->next;
        return dummy->next;
    }
};