// Problem - Valid Parenthesis (20) - LeetCode

#include<iostream>
#include <stack>
#include <string>
#include<vector>
using namespace std;

bool isValid(string str) {
    stack<char> st;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') { // opening
            st.push(str[i]);
        }
        else { // closing
            if(st.empty()) {  // check stack, not str
                return false;
            }
            if((st.top() == '(' && str[i] == ')') || 
               (st.top() == '{' && str[i] == '}') || 
               (st.top() == '[' && str[i] == ']')) { // match
                st.pop();
            }
            else { // not match
                return false;
            }
        }
    }
    return st.empty();  // final check
}

int main() {
    vector<string> testCases = {
        "()",        // valid
        "()[]{}",    // valid
        "(]",        // invalid
        "([)]",      // invalid
        "{[]}",      // valid
        "",          // valid (empty string)
        "(",         // invalid
        "]",         // invalid
        "{{{{}}}}"   // valid
    };

    for (const string& test : testCases) {
        cout << "Input: \"" << test << "\" -> ";
        if (isValid(test)) {
            cout << "Valid" << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}