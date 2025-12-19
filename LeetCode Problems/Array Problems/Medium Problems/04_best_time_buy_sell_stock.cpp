// Problem - Best Time to Buy and Sell stock using Strategy (3652) - LeetCode

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    int n = prices.size();
    int half = k / 2;

    long long original = 0;
    for (int i = 0; i < n; i++) {
        original += 1LL * strategy[i] * prices[i];
    }

    long long currentDelta = 0;

    // Initial window [0..k-1]
    for (int j = 0; j < half; j++) {
        currentDelta += -1LL * strategy[j] * prices[j];                 // first half -> 0
    }
    for (int j = half; j < k; j++) {
        currentDelta += 1LL * prices[j] * (1 - strategy[j]);            // second half -> 1
    }

    // Allow "no modification" by clamping at 0
    long long bestDelta = max(0LL, currentDelta);

    // Slide window start s from 1 to n-k
    for (int s = 1; s + k <= n; s++) {
        int leaveFirst = s - 1;
        int pivot      = s - 1 + half;      // moves from old second half to new first half
        int enterSecond = s - 1 + k;        // new element entering second half

        // remove old first-half contribution of leaving element
        currentDelta -= -1LL * strategy[leaveFirst] * prices[leaveFirst];

        // pivot: remove its old second-half role, add its new first-half role
        currentDelta -= 1LL * prices[pivot] * (1 - strategy[pivot]);
        currentDelta += -1LL * strategy[pivot] * prices[pivot];

        // add new second-half entrant
        currentDelta += 1LL * prices[enterSecond] * (1 - strategy[enterSecond]);

        bestDelta = max(bestDelta, currentDelta);
    }
    return original + bestDelta;
}


int main() {
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    vector<int> strategy = {0, 1, 1, 0, 0, 1}; // 1 = buy, 0 = do nothing
    int k = 4; // Strategy window size

    long long result = maxProfit(prices, strategy, k);

    cout << "Maximum profit: " << result << endl;

    return 0;
}