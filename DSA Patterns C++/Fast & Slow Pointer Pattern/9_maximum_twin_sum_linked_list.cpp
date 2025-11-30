// Problem - Maximum Twin Sum of a Linked List (2130) - LeetCode
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

    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *p2 = reverseLinkedList(slow);
        ListNode *p1 = head;

        int mx = INT_MIN;   // use different name
        while(p1 != NULL && p2 != NULL) {
            int candidate = p1->val + p2->val;
            mx = std::max(mx, candidate);
            p1 = p1->next;
            p2 = p2->next;
        }
        return mx;
    }
};