// Problem - Maximum Total from Optimal Activation Order (3645) - LeetCode

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

long long maxTotal(vector<int>& value, vector<int>& limit) {
    int n = value.size();
    vector<pair<int,int>> arr(n); // {limit, value}
    for (int i = 0; i < n; ++i) arr[i] = {limit[i], value[i]};

    // Sort by limit ascending; for equal limit, value descending
    sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    vector<int> picked(n, 0); // picked[j] = 1 if we activated arr[j]
    int i = 0, j = 0;
    long long ans = 0;
    int active = 0; // number of currently active elements

    while (j < n) {
        int l = arr[j].first;
        int v = arr[j].second;

        if (active < l) {
            // we can activate this element
            picked[j] = 1;
            ans += v;
            ++active;

            // if active == l, then any element with limit == active becomes permanently inactive
            if (active == l) {
                while (j < n && arr[j].first == active) ++j;
            } else {
                ++j;
            }
        } else {
            // cannot activate arr[j] now; move on
            ++j;
        }

        // slide i forward: remove elements whose limit <= active from the active count
        while (i < j && arr[i].first <= active) {
            active -= picked[i];
            ++i;
        }
    }

    return ans;
}

int main() {
    vector<int> value = {10, 20, 30, 40};
    vector<int> limit = {1, 2, 1, 3};

    long long result = maxTotal(value, limit);
    cout << "Maximum total from optimal activation order: " << result << endl;

    return 0;
}