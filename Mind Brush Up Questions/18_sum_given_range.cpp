//? sum of numbers in a given range

#include<iostream>
using namespace std;

int sumOfRange(int m,int n) {
    int sum = 0;
    for(int i = m; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int m,n;
    cout << "Enter the starting range: ";
    cin >> m;
    cout << "Enter the ending range: ";
    cin >> n;
    int result = sumOfRange(m,n);
    cout << "Sum of numbers in a given range is: " << result;
    return 0;
}