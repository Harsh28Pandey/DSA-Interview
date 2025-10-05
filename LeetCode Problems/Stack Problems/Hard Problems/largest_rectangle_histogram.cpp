// Problem - Largest Rectangle in Histogram (84) - LeetCode
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0); // left smaller element
    vector<int> right(n, 0); // right smaller element
    stack<int> s;

    // right smaller nearest
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    while (!s.empty()) {
        s.pop();
    }

    // left smaller nearest
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }
    return ans;
}

int main() {
    vector<int> heights;

    // Example 1: Input from user
    cout << "Enter the number of bars in the histogram: ";
    int n;
    cin >> n;
    cout << "Enter the heights of the bars:\n";
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        heights.push_back(h);
    }

    int maxArea = largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << maxArea << endl;

    return 0;
}