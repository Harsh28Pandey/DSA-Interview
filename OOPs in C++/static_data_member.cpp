#include<iostream>
using namespace std;
class Customer {
    string name;
    int acc_no, balance;
    static int total_customer;
    static int total_balance;
public:
    Customer(string name,int acc_no,int balance) {
        this->name = name;
        this->acc_no = acc_no;
        this->balance = balance;
        total_customer++;
        total_balance += balance;
    }
    void display() {
        cout<<name<<" "<<acc_no<<" "<<balance<<" "<<total_customer<<endl;
    }
    void display_total() {
        cout<<total_customer<<endl;
    }
    static void access_static() {
        cout<<"Total number of customer: "<<total_customer<<endl;
        cout<<"Total balance: "<<total_balance<<endl;
    }
    void deposit(int amount) {
        if(amount > 0) {
            balance += amount;
            total_balance += amount;
        }
    }
    void withdraw(int amount) {
        if(amount <= balance && amount > 0) {
            balance -= amount;
            total_balance -= amount;
        }
    }
};

int Customer::total_customer = 0;
int Customer::total_balance = 0;

int main() {
    Customer A1("Rohit",1,1000);
    Customer A2("Mohit",2,2000);
    A1.display();
    A2.display();
    Customer A3("Rohan",3,2500);
    Customer::access_static();
    A3.display_total();
    A1.deposit(1000);
    Customer::access_static();
}