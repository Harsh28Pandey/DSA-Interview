// Problem - Interval List Intersections (986) - LeetCode
// Time Complexity - O(m + n)
// Space Complexity - O(m + n)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];
            int s2 = secondList[j][0];
            int e2 = secondList[j][1];

            // check overlap
            if (e1 >= s2 && e2 >= s1) {
                ans.push_back({max(s1, s2), min(e1, e2)});
            }

            // move pointer
            if (e1 < e2)
                i++;
            else
                j++;
        }

        return ans;
    }
};