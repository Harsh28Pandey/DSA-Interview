// Problem - Min Stack (155) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <stack>
#include <utility> // for std::pair
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s; // val, minVal

    MinStack() {}

    void push(int val) {
        if(s.empty()) {
            s.push({val, val});
        } else {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

int main() {
    MinStack minStack;

    minStack.push(5);
    cout << "Pushed 5, Current Min: " << minStack.getMin() << endl;

    minStack.push(3);
    cout << "Pushed 3, Current Min: " << minStack.getMin() << endl;

    minStack.push(7);
    cout << "Pushed 7, Current Min: " << minStack.getMin() << endl;

    cout << "Top: " << minStack.top() << endl;

    minStack.pop();
    cout << "Popped, Current Min: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "Popped, Current Min: " << minStack.getMin() << endl;

    return 0;
}