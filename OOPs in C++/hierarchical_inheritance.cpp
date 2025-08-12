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


class Teacher : public Human {
    int salary;
    public:
    Teacher(int salary,string name,int age) {
        this->salary = salary;
        this->name = name;
        this->age = age;
    }
    void display() {
        cout << name << " " << age << " " << salary << endl;
    }
};

int main()
{
    Student S1("Harsh",12,10,99);
    // S1.display();
    Teacher T1(12,"Mohit",22);
    T1.display();
}