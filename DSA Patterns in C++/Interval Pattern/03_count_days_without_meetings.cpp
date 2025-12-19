// Problem - Count Days Without Meetings (3169) - LeetCode
// Time Complexity - O(n log n)
// Space Complexity - O(n)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        sort(meetings.begin(), meetings.end());

        vector<vector<int>> result;
        result.push_back(meetings[0]);

        // Merge intervals
        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], meetings[i][1]);
            } else {
                result.push_back(meetings[i]);
            }
        }

        int gap = 0;

        // gap before first meeting
        gap += result[0][0] - 1;

        // gaps between meetings
        for (int i = 1; i < result.size(); i++) {
            gap += result[i][0] - result[i - 1][1] - 1;
        }

        // gap after last meeting
        gap += days - result.back()[1];

        return gap;
    }
};