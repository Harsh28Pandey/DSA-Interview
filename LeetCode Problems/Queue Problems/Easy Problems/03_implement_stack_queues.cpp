// Problem - Implement Stack using Queues (225) - LeetCode

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() { }
    
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;  // 30
    cout << "Pop element: " << st.pop() << endl;  // 30
    cout << "Top after pop: " << st.top() << endl; // 20

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.pop(); // removes 20
    st.pop(); // removes 10

    cout << "Is stack empty after removing all? " 
         << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}