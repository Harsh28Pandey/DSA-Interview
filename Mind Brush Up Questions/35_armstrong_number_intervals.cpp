//? armstrong number between two intervals

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int start, end;

    cout << "Enter interval (start end): ";
    cin >> start >> end;

    cout << "Armstrong numbers between " << start << " and " << end << " are:\n";

    for(int num = start; num <= end; num++) {
        int temp = num;
        int sum = 0;
        int digits = 0;

        int countTemp = temp;
        while(countTemp != 0) {
            countTemp /= 10;
            digits++;
        }

        temp = num;

        while(temp != 0) {
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }

        if(sum == num)
            cout << num << " ";
    }

    return 0;
}
