#include<iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int currSize,capacity;
    int front,rear;
    public:

    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        currSize = 0;
        front = 0;
        rear = -1;
    }

    void push(int data) {
        if(currSize == capacity) {
            cout << "CQ is full \n";
            return ;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        currSize++;
    }

    void pop() {
        if(empty()) {
            cout << "CQ is empty \n";
            return ;
        }
        rear = (front + 1) % capacity;
        currSize--;
    }

    int front() [
        if(empty()) {
            cout << "CQ is empty \n";
            return -1;
        }
        return arr[front];
    ]

    bool empty() {
        return currSize == 0;
    }

    void printArr() {
        for(int i = 0; i < capacity; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.pop();
    cq.push(40);
    // while(!cq.empty()) {
    //     cout << cq.front() << " ";
    //     cq.pop();
    // }
    // cout << endl;
    cq.printArr();
    return 0;
}