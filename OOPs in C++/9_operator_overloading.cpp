#include<iostream>
using namespace std;

class Complex {
    int real,img;
    public:
    Complex() {

    };
    Complex(int real,int img) {
        this->real = real;
        this->img = img;
    };
    void display() {
        cout<< real <<" + i" <<img << endl;
    }
    Complex operator +(Complex &c) {
        Complex ans;
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }
};

int main()
{
    Complex C1(3,4);
    Complex C2(4,6);
    Complex C3 = C1 + C2;
    C3.display();
}