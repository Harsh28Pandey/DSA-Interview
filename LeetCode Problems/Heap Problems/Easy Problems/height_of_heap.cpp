// Problem - Height of a Heap - gfg

#include <iostream>
using namespace std;

int heapHeight(int n, int arr[]) {
    if (n == 1)
        return 1;

    int height = 0;
    while (n > 1) {
        height++;
        n /= 2;
    }
    return height;
}

int main() {
    int arr[] = {10, 20, 30, 25, 5, 40, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Heap Height: " << heapHeight(n, arr) << endl;

    return 0;
}