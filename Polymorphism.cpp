#include<iostream>
using namespace std;

//POLYMORPHISM - is a feature of OOP which allows us to use a single interface to represent different types of objects. In C++, polymorphism is achieved through function overloading and operator overloading.
// EXAMPLE CONSTRUCTOR OVERLOADING IS AN EXAMPLE OF PLOYMORPHISM
class Student{
    public:
    string name;
    
    Student(){
        cout<<"non- parameterized const"<<endl;
    }
    Student(string name){
        cout<<"parameterized const"<<endl;
        this->name = name;
    }
    
};


int main(){
    Student s1("tony stark");


    return 0;
}