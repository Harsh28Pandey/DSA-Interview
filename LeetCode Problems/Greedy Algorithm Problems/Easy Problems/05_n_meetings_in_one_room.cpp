// Problem - N Meetings in One Room - gfg
// Time Complexity: O(N log N)
// Space Complexity: O(N)

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>> timer;

        for (int i = 0; i < n; i++) {
            timer.push_back({end[i], start[i]}); // store end first
        }

        sort(timer.begin(), timer.end());

        int total = 0;
        int ending = -1;

        for (int i = 0; i < n; i++) {
            if (timer[i].second > ending) {
                total++;
                ending = timer[i].first;
            }
        }
        return total;
    }
};