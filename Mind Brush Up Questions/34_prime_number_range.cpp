//? prime number in a given range

#include<iostream>
using namespace std;

int main() {
    int start,end;
    cout << "Enter the start number: ";
    cin >> start;
    cout << "Enter the end number: ";
    cin >> end;
    
    cout << "Prime number between " << start << " and " << end << " are: ";
    for(int i = start; i <= end; i++) {
        if(i <= 1)
        continue;

        bool isPrime = true;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            cout << i << " ";
    }
    return 0;
}