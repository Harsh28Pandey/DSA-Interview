#include<iostream>
using namespace std;
class Customer {
    string name;
    int acc_no, balance,age;
public:
    Customer(string name,int acc_no,int age) {
        this->name = name;
        this->acc_no = acc_no;
        this->age = age;
    }
    void update_age(int age) {
        if(age > 0 && age < 100) {
            this->age = age;
        }
        else {
            cout<<"Invalid age"<<endl;
        }
    }
    void display() {
        cout<<name<<" "<<acc_no<<" "<<" "<<age<<endl;
    }
};
int main() {
    Customer A1("Rohit",1000,2);
    Customer A2("Mohit",2000,3);
    Customer A3("Mohan",4000,4);
    A1.display();
    A2.update_age(-34);
}