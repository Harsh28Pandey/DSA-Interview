//? strong number or not

#include<iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

 void strongNumber(int n){
    int temp = n;
    int result = 0;
        while(temp != 0) {
            int rem = temp % 10;
            result += factorial(rem);
            temp /= 10;
        }
        if(n == result) {
            cout << "Number is strong" << endl;
        } else {
            cout << "Number is not strong" << endl;
        }
   }

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    strongNumber(n);
    return 0;
}