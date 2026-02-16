//? Area of circle

#include<iostream>
using namespace std;

int main() {
    int radius;
    cout << "Enter the radius: ";
    cin >> radius;
    float area = 3.14 * radius * radius;
    cout << "Area of circle: " << area;
    return 0;
}