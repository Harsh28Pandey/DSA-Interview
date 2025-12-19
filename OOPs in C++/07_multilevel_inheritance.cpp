#include<iostream>
using namespace std;

class Person {
    protected:
    string name;
    public:
    void introduce() {
        cout << "Hello " << name << endl;
    }
};

class Employee : public Person {
    protected:
    int salary;
    public:
    void monthly_salary() {
        cout << "monthly Salary: " << salary << endl;
    }
};

class Manager : public Employee {
    public:
    string department;
    Manager(string name,int salary,string department) {
        this->name = name;
        this->salary = salary;
        this->department = department;
    };
    void work() {
        cout << "I am leading " << department << endl;
    }
};

int main()
{
    Manager M1("Harsh",200,"Finance");
    M1.monthly_salary();
    M1.introduce();
}