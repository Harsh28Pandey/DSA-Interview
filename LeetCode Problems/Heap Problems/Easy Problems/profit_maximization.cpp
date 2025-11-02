#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int maxProfit(vector<int> &arr, int b) {
    int sum = 0;
    priority_queue<int> p; // max heap

    for(int i = 0; i < arr.size(); i++) {
        p.push(arr[i]);
    }

    // sell the ticket to b people
    while(b && !p.empty()) {
        sum += p.top(); // top ticket price

        if(p.top() - 1)
        p.push(p.top() - 1);

        p.pop();
        b--; // ticket sell
    }
    return sum;
}

int main() {
    int n, b;
    cout << "Enter number of rows and number of buyers: ";
    cin >> n >> b;

    vector<int> arr(n);
    cout << "Enter the number of tickets available in each row: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum profit: " << maxProfit(arr, b) << endl;
    return 0;
}