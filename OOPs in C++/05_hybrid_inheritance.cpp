#include<iostream>
using namespace std;

// Student
// boy
// girl
// male
// female

class Student {
    public:
    void print() {
        cout << "I am a student" << endl;
    }
};

class Boy : public Student, Male {
    public:
    void BoyPrint() {
        cout << "I am a boy" << endl;
    }
};

class Girl : public Student, Female {
    public:
    void GirlPrint() {
        cout << "I am a girl" << endl;
    }
};

class Male {
    public:
    void MalePrint() {
        cout << "I am Male" << endl;
    }
};

class Female {
    public:
    void FemalePrint() {
        cout << "I am Female" << endl;
    }
};

int main()
{
    Girl G1;
    G1.GirlPrint();
    G1.print();
    Boy B1;
    // B1.MalePrint();
    B1.print();
}