// Problem - Add Two Numbers (2) - LeetCode

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Number 1: 342 (represented as 2 -> 4 -> 3)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Number 2: 465 (represented as 5 -> 6 -> 4)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Output the result
    cout << "Result: ";
    printList(result);

    return 0;
}