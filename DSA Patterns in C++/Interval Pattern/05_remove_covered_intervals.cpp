// Problem - Remove Covered Intervals (1288) - LeetCode
// Time Complexity - O(n log n)
// Space Complexity - O(n)

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) 
        return 0;

        // Sort by start asc, and if start same, end desc
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 1;                  // first interval is always kept
        int maxEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] > maxEnd) {
                count++;
                maxEnd = intervals[i][1];
            }
            // else: interval is covered, ignore
        }

        return count;
    }
};