#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minimumChocolates(int a, vector<int> &arr) {
    priority_queue<int> p; // max heap
    for(int i = 0; i < arr.size(); i++) {
        p.push(arr[i]);
    }

    long long maxChocolates = 0;
    while(a && (!p.empty())) {
        maxChocolates += p.top();
        if(p.top() / 2);
        p.push(p.top() / 2);
        p.pop();
        a--;
    }
    return maxChocolates % 1000000007;
}

int main() {
    int n, a;
    cout << "Enter number of bags and time units: ";
    cin >> n >> a;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minimumChocolates(a, arr) << endl;

    return 0;
}