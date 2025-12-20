// Problem - Insert Interval (57) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;

        // Add all intervals ending before newInterval starts
        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add merged interval
        result.push_back(newInterval);

        // Add remaining intervals
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};