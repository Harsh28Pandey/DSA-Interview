// Problem - Preorder Traversal and BST - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)

#include<iostream>
#include<stack>
#include<climits>
using namespace std;

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int> lower, upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int lowerBound, upperBound;
        
        for(int i = 0; i < N; i++) {
            if(arr[i] < lower.top())
                return 0;
            
            while(!upper.empty() && arr[i] > upper.top()) {
                upper.pop();
                lower.pop();
            }
            
            lowerBound = lower.top();
            upperBound = upper.top();
            lower.pop();
            upper.pop();
            
            // right side
            lower.push(arr[i]);
            upper.push(upperBound);
            
            // left side
            lower.push(lowerBound);
            upper.push(arr[i]);
        }
        return 1;
    }
};

int main() {
    Solution obj;

    int arr1[] = {40, 30, 35, 80, 100};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {40, 30, 35, 20, 80, 100};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Test case 1: ";
    if(obj.canRepresentBST(arr1, N1)) cout << "Yes, can represent BST" << endl;
    else cout << "No, cannot represent BST" << endl;

    cout << "Test case 2: ";
    if(obj.canRepresentBST(arr2, N2)) cout << "Yes, can represent BST" << endl;
    else cout << "No, cannot represent BST" << endl;

    return 0;
}