#include <iostream>
#include <queue>
using namespace std;

long long sumBetweenTwoKth(long long arr[], long long n, long long k1, long long k2) {
    // max heaps
    priority_queue<long long> p1;
    priority_queue<long long> p2;

    // insert k1 elements into p1
    for (long long i = 0; i < k1; i++) {
        p1.push(arr[i]);
    }

    // insert k2 elements into p2
    for (long long i = 0; i < k2; i++) {
        p2.push(arr[i]);
    }

    // find k1 smallest elements
    for (long long i = k1; i < n; i++) {
        if (arr[i] < p1.top()) {
            p1.pop();
            p1.push(arr[i]);
        }
    }

    // find k2 smallest elements
    for (long long i = k2; i < n; i++) {
        if (arr[i] < p2.top()) {
            p2.pop();
            p2.push(arr[i]);
        }
    }

    // sum elements between k1-th and k2-th smallest
    long long first = p1.top();
    long long second = p2.top();
    long long sum = 0;

    for (long long i = 0; i < n; i++) {
        if (arr[i] > first && arr[i] < second) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    long long n, k1, k2;
    cout << "Enter number of elements: ";
    cin >> n;

    long long arr[n];
    cout << "Enter the elements: ";
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k1 and k2: ";
    cin >> k1 >> k2;

    cout << "Sum of elements between " << k1 << "th and " << k2 << "th smallest elements is: "
         << sumBetweenTwoKth(arr, n, k1, k2) << endl;

    return 0;
}