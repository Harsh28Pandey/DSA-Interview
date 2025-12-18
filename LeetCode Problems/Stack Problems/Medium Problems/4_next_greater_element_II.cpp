// Problem - Next Greater Element II (505) - LeetCode
// Time Complexity : O(2n) -> O(n)
// Space Complexity : O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for(int i = 2 * n - 1; i >= 0; i--) {
        while(!s.empty() && nums[s.top()] <= nums[i % n]) {
            s.pop();
        }
        ans[i % n] = s.empty() ? -1 : nums[s.top()];
        s.push(i % n);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = nextGreaterElements(nums);

    cout << "Next greater elements: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}