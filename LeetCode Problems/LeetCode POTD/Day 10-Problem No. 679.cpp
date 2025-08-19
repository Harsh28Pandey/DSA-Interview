// Problem - 24 Game (679) - LeetCode

bool judgePoint24(vector<int>& cards) {
    vector<double> nums(cards.begin(), cards.end());
    return solve(nums);
}
private:
const double EPS = 1e-6;

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