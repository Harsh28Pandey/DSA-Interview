// Problem - Smallest Range Covering Elements from K Lists (632) - LeetCode
// Time Complexity - O(n * K log K)
// where K is no. of rows or K lists and n is harr row me kitne column hai

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> p;
        int minimum, maximum = INT_MIN;

        // insert first element of each row into heap
        for(int i = 0; i < nums.size(); i++) {
            p.push(make_pair(nums[i][0], make_pair(i,0)));
            maximum = max(maximum, nums[i][0]);
        }

        minimum = p.top().first;
        vector<int> ans(2);
        ans[0] = minimum;
        ans[1] = maximum;

        pair<int,pair<int,int>> temp;
        int row,col,element;

        while(p.size() == nums.size()) {
            temp = p.top();
            p.pop();
            element = temp.first;
            row = temp.second.first;
            col = temp.second.second;

            if(col + 1 < nums[row].size()) {
                col++;
                p.push(make_pair(nums[row][col], make_pair(row,col)));
                maximum = max(maximum,nums[row][col]);
                minimum = p.top().first;

                // Update smallest range
                if(maximum - minimum < ans[1] - ans[0]) {
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> range = sol.smallestRange(nums);

    cout << "Smallest range is: [" << range[0] << ", " << range[1] << "]" << endl;

    return 0;
}