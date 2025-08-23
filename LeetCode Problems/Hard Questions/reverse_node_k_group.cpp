// Problem - Reverse Nodes in K Groups (25) - LeetCode

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Your reverseKGroup function
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int count = 0;

    // check if k nodes exist
    while (count < k) {
        if (temp == nullptr) {
            return head;
        }
        temp = temp->next;
        count++;
    }

    // recursively call for rest of linked list
    ListNode* prevNode = reverseKGroup(temp, k);

    // reverse current group
    temp = head;
    count = 0;
    while (count < k) {
        ListNode* next = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = next;
        count++;
    }
    return prevNode;
}

// Helper function to create linked list from array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete linked list and free memory
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;

    ListNode* head = createList(arr, sizeof(arr)/sizeof(arr[0]));

    cout << "Original list:\n";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ":\n";
    printList(head);

    deleteList(head);
    return 0;
}