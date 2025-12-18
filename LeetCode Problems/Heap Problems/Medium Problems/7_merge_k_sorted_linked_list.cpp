// Problem - Merge K Sorted Linked List - gfg

#include <bits/stdc++.h>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Comparator for min-heap (priority queue)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Min-heap to get the smallest node among all lists
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        // Push the head of each list into the heap
        for (auto node : arr) {
            if (node) pq.push(node);
        }
        
        // Dummy node to start the merged list
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        // Extract the minimum node and push its next node into the heap
        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            
            tail->next = temp;
            tail = tail->next;
            
            if (temp->next)
                pq.push(temp->next);
        }
        
        return dummy->next;
    }
};

// Helper function to print a linked list
void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Helper to create a linked list from a vector
Node* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* temp = head;
    for (size_t i = 1; i < vals.size(); i++) {
        temp->next = new Node(vals[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    // Example input: 3 sorted linked lists
    vector<int> list1 = {1, 4, 5};
    vector<int> list2 = {1, 3, 4};
    vector<int> list3 = {2, 6};
    
    // Convert vectors to linked lists
    Node* l1 = createList(list1);
    Node* l2 = createList(list2);
    Node* l3 = createList(list3);
    
    // Store them in a vector
    vector<Node*> arr = {l1, l2, l3};
    
    // Merge all lists
    Solution sol;
    Node* mergedHead = sol.mergeKLists(arr);
    
    // Print merged linked list
    cout << "Merged Linked List: ";
    printList(mergedHead);
    
    return 0;
}