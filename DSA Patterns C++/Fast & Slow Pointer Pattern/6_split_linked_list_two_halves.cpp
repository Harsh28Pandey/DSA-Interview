// Problem - Split a Linked List into Two Halves - GeeksForGeeks
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        Node *slow = head;
        Node *fast = head->next;
        
        while(fast != head && fast->next != head) {
            slow = slow->next;
            fast = fast->next;
            
            if(fast->next != head) {
                fast = fast->next;
            }
        }
        
        fast->next = slow->next;
        slow->next = head;
        
        return make_pair(head, fast->next);

    }
};