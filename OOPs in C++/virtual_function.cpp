#include<iostream>
#include<vector>
using namespace std;

class Animal {
    public:
    virtual void speak() {
        cout << "Huhu" << endl;
    }
};

class Dog : public Animal {
    public:
    void speak() {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
    public:
    void speak() {
        cout << "Meow" << endl;
    }
};

int main() 
{
    // Animal *p;
    // p = new Dog();
    // p->speak();

    Animal *p;
    vector<Animal*>animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());

    for(int i = 0; i < 5; i++) {
        p = animals[i];
        p->speak();
    }
 }