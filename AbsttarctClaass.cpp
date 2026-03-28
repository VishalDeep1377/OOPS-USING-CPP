#include<iostream>
using namespace std;

//ABSTRACT CLASS - is a class which cannot be instantiated and is used as a base class for other classes. An abstract class is a class which contains at least one pure virtual function. A pure virtual function is a function which is declared in the base class and is not defined in the base class. The pure virtual function is defined in the derived class. The abstract class is used to achieve abstraction in C++. Abstraction is a process of hiding the implementation details and showing only the functionality to the user.

class Shape{ //ABSTRACT CLASS
    virtual void draw() = 0; // pure virtual function - is a function which is declared in the base class and is not defined in the base class.
};

class Circle : public Shape{ //DERIVED CLASS
    public:
    void draw(){ // pure virtual function is defined in the derived class
        cout<<"drawing circle"<<endl;
    }
};

int main(){

    Circle c1;
    c1.draw();




    return 0;

}