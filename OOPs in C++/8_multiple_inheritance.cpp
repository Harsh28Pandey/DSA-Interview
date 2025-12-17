#include<iostream>
using namespace std;

class Engineer {
    public:
    string specialization;
    void work() {
        cout << "I have specialization in " << specialization << endl;
    }
};

class Youtuber {
    public:
    int subscriber;
    void content_area() {
        cout << "Subscriber base " << subscriber << endl;
    }
};

class CodeTeacher : public Engineer, Youtuber {
    public:
    string name;
    CodeTeacher(string name,string specialization,int subscriber) {
        this->name = name;
        this->specialization = specialization;
        this->subscriber = subscriber;
    }
    void display() {
        cout << name;
        work();
        content_area();
    }
};

int main()
{
    CodeTeacher T1("Harsh","CSE",500000);
    T1.display();
    T1.work();
}