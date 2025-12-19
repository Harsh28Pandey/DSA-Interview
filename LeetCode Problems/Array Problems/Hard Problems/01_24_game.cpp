// Problem - 24 Game (679) - LeetCode

#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

const double EPS = 1e-6;

vector<double> compute(double a, double b) {
    vector<double> res;
    res.push_back(a + b);
    res.push_back(a - b);
    res.push_back(b - a);
    res.push_back(a * b);
    if (fabs(b) > EPS) res.push_back(a / b);
    if (fabs(a) > EPS) res.push_back(b / a);
    return res;
}

bool solve(vector<double>& nums) {
    int n = nums.size();
    if (n == 1) {
        return fabs(nums[0] - 24) < EPS;
    }

    // Try every pair of numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            // remaining numbers after removing nums[i] and nums[j]
            vector<double> next;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) next.push_back(nums[k]);
            }

            // Try all operations
            for (auto val : compute(nums[i], nums[j])) {
                next.push_back(val);
                if (solve(next)) return true;
                next.pop_back();
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int>& cards) {
    vector<double> nums(cards.begin(), cards.end());
    return solve(nums);
}

int main() {
    vector<int> cards;
    cout << "Enter 4 card values (1 to 13): ";
    for (int i = 0; i < 4; ++i) {
        int val;
        cin >> val;
        cards.push_back(val);
    }

    if (judgePoint24(cards)) {
        cout << "It's possible to reach 24." << endl;
    } else {
        cout << "It's NOT possible to reach 24." << endl;
    }

    return 0;
}