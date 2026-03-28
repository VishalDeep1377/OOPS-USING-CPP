#include<iostream>
using namespace std;

//FUNCTION OVERLOADING - is a feature of OOP which allows us to use the same function name for different types of functions. In C++, we can overload functions by changing the number of parameters or by changing the data type of parameters.

class Print{
    public:
    void show(int x){
        cout<<"the value of x is "<<x<<endl;
    }
    void show(char x){
        cout<<"the value of x is "<<x<<endl;
    }
};

int main(){
    Print p1;
    // p1.show(10);
    p1.show('A');


    return 0;
}