// Problem - magnetic force between two balls (1552) - LeetCode

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(const vector<int>& arr, int n, int c, int maxAllowedDistance) {
    int balls = 1; // Place first ball at the first position
    int lastBallPosition = arr[0];

    for(int i = 1; i < n; ++i) {
        if(arr[i] - lastBallPosition >= maxAllowedDistance) {
            balls++;
            lastBallPosition = arr[i];
        }
        if(balls == c) {
            return true; // Successfully placed all balls
        }
    }
    return false; // Not possible with this distance
}

int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(), position.end()); // Sort the positions first

    int start = 1;
    int end = position[n - 1] - position[0];
    int ans = -1;

    // Binary search for the largest minimum distance
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(isPossible(position, n, m, mid)) {
            ans = mid;        // Valid, try for more
            start = mid + 1;
        } else {
            end = mid - 1;    // Not valid, reduce distance
        }
    }

    return ans;
}

int main() {
    vector<int> position = {1, 2, 4, 8, 9};
    int m = 3; // Number of balls to place
    cout << "Maximum distance between the balls: " << maxDistance(position, m) << endl;
    return 0;
}