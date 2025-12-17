#include<iostream>
using namespace std;

class Human {
    protected:
    string name;
    int age;

    public:
    void work() {
        cout << "I am working" << endl;
    }
};

class Student : public Human {
    int roll_no,fees;
    public:
    Student(string name,int age,int roll_no,int fees) {
        this->name = name;
        this->age = age;
        this->roll_no = roll_no;
        this->fees = fees;
    };
    Student() {
        cout << "Hello Student" << endl;
    };
};

int main()
{
    Student A1("Harsh",26,10,2600);
    A1.work();
}