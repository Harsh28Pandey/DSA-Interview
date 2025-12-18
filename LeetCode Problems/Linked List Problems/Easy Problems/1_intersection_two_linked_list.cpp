// Problem - Intersection of Two Linked List (160) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr; // If either list is empty

    ListNode *pA = headA;
    ListNode *pB = headB;

    while (pA != pB) {
        // Move pointer forward, if null redirect to other list's head
        pA = (pA == nullptr) ? headB : pA->next;
        pB = (pB == nullptr) ? headA : pB->next;
    }

    // Either intersection node or nullptr
    return pA;
}

int main() {
    // Creating shared part of the list
    ListNode *intersect = new ListNode(8);
    intersect->next = new ListNode(10);

    // Creating first list: 3 -> 7 -> 8 -> 10
    ListNode *headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = intersect;

    // Creating second list: 99 -> 1 -> 8 -> 10
    ListNode *headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = intersect;

    // Find intersection
    ListNode *result = getIntersectionNode(headA, headB);

    if (result)
        cout << "Intersection at node with value: " << result->val << endl;
    else
        cout << "No intersection." << endl;

    // Clean up memory (optional for small demo)
    delete headA->next;
    delete headB->next;
    delete intersect->next;
    delete intersect;

    return 0;
}