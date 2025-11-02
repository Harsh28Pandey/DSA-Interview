// Problem - Last Stone Weight (1046) - LeetCode

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> p;
    for (int i = 0; i < stones.size(); i++) {
        p.push(stones[i]);
    }

    while (p.size() > 1) {
        int weight = p.top();
        p.pop();
        weight -= p.top();
        p.pop();

        if (weight)
            p.push(weight);
    }

    return p.empty() ? 0 : p.top();
}

int main() {
    int n;
    cout << "Enter number of stones: ";
    cin >> n;
    vector<int> stones(n);
    cout << "Enter stone weights: ";
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    cout << "Last stone weight: " << lastStoneWeight(stones) << endl;
    return 0;
}
