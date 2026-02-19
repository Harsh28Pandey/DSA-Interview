//? replace all 0's with 1 in a given integer

#include <iostream>
using namespace std;

int main() {
    int num, result = 0, place = 1;

    cout << "Enter a number: ";
    cin >> num;

    if(num == 0) {
        cout << "Result: 1";
        return 0;
    }

    while(num > 0) {
        int digit = num % 10;

        if(digit == 0)
            digit = 1;

        result += digit * place;
        place *= 10;
        num /= 10;
    }

    cout << "Result: " << result;

    return 0;
}
