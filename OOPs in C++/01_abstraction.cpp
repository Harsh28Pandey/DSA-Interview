#include<iostream>
using namespace std;
class Customer {
    string name;
    int balance;
public:
    Customer(string a,int b) {
        name = a;
        balance = b;
    }
    void deposit(int amount) {
        if(amount > 0) {
            balance += amount;
        }
    }
    void display() {
        cout<<name<<" "<<balance<<endl;
    }
};

int main() {
    Customer A1("Rohit",300);
    A1.deposit(500);
    A1.display();
}