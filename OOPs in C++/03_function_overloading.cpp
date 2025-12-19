#include<iostream>
using namespace std;

class Area {
    public:
    int calculate_area(int r) {
        return 3.14 * r * r;
    }
    int calculate_area(int l,int b) {
        return l * b;
    }
};

int main()
{
    Area A1,A2;
    cout<<A1.calculate_area(4)<<endl;
    cout<<A2.calculate_area(3,4)<<endl;
}