// Problem - Merge Intervals (56) - LeetCode
// Time Complexity - O(n ^ 3) > O(n log n)
// Space Complexity - O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        // Step 2: Merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with last merged interval
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } 
            // No overlap
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
