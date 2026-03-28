#include<iostream>
using namespace std;

//STATIC VARIABLES - is a variable which is shared by all the objects of a class. A static variable is initialized only once and its value is shared by all the objects of the class. A static variable can be accessed using the class name and the scope resolution operator (::) without creating an object of the class.


class A{
    public:
    int x;

    void incX(){
        x++;
    }
};


int main(){

    A obj1;
    A obj2;

    obj1.x = 100;
    obj2.x = 200;

    cout<<obj1.x<<endl;
    cout<<obj2.x<<endl;


  


    return 0;

}