// Time Complexity - O(n * log n)

#include<iostream>
using namespace std;

class MaxHeap {
    int *arr;
    int size; // total elements in heap
    int totalSize; // total size of array
    
    public:

    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        totalSize = n;
    }

    // insert into the max heap
    void insert(int value) {
        // if heap size is avaliable or not
        if(size == totalSize) {
            cout << "Heap overflow" << endl;
            return ;
        }

        arr[size] = value;
        int index = size;
        size++;

        // compare it with its parent
        while(index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index],arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " is inserted into the heap" << endl;
    }

    // print the elements of max heap
    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h(6);
    h.insert(4);
    h.insert(14);
    h.insert(11);
    h.insert(12);
    h.insert(20);
    h.insert(30);
    h.print();
    h.insert(100);
    return 0;
}