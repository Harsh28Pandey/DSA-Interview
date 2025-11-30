// Problem - Find the Length of Loop - GeeksForGeeks
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
    int lengthOfLoop(Node head) {
        Node *slow = head;
        Node *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                // cycle
                break;
            }
        }

        if(fast == NULL || fast->next == NULL) {
            return 0;
        }

        Node *n1 = head;
        Node *n2 = slow;

        while(n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }

        int length = 0;
        Node *curr = n1->next;
        while(curr != n1) {
            length = length + 1;
            curr = curr->next;
        }
        return length;
    }
}