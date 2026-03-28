#include<iostream>
using namespace std;
//FUNCTION OVERRIDDEN - is a feature of OOP which allows us to redefine a function in the derived class which is already defined in the base class. In C++, we can override a function by using the same function name and the same parameters in the derived class as in the base class. The function in the derived class will be called when we call the function using an object of the derived class.  

class Parent{
    public:
    void show(){
        cout<<"hii i am parent class"<<endl;
    };
    virtual void display(){ // virtual function - is a function which is declared in the base class and is redefined in the derived class. The virtual function is used to achieve runtime polymorphism. When we call a virtual function using a pointer of the base class, the function of the derived class will be called if the pointer is pointing to an object of the derived class. If the pointer is pointing to an object of the base class, then the function of the base class will be called.
        cout<<"hii i am parent class display function"<<endl;
    };
};

class Child : public Parent{
    public:
    void show(){
        cout<<"hii i am child class"<<endl;
    };
    void display(){ // function overriding - is a feature of OOP which allows us to redefine a function in the derived class which is already defined in the base class. In C++, we can override a function by using the same function name and the same parameters in the derived class as in the base class. The function in the derived class will be called when we call the function using an object of the derived class.  
        cout<<"hii i am child class display function"<<endl;
    };
};

int main(){

    // Child c1;
    // c1.show();

    Parent p1;
    p1.show();
    p1.display();



    return 0;

}