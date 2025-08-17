// Problem - Time Needed to Buy Tickets (2073) - LeetCode

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    queue<int>q;
    int n = tickets.size();
    for(int i = 0; i < n; i++) {
        q.push(i);
    }
    int time = 0;
    while(tickets[k] != 0) {
        tickets[q.front()]--;
        // kya line mein lagega
        if(tickets[q.front()]) {
            q.push(q.front());
        }
        q.pop();
        time++;
    }
    return time;
}

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    int result = timeRequiredToBuy(tickets, k);
    cout << "Time needed to buy tickets for person " << k << " is: " << result << endl;

    return 0;
}