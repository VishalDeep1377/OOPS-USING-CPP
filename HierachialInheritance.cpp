#include<iostream>
#include<string>
using namespace std;

// inheritance - is a feature of OOP which allows us to create a new class from an existing class. The new class is called derived class and the existing class is called base class. The derived class inherits all the properties and methods of the base class.
//HEIRARCHIAL INHERITANCE - is a type of inheritance in which multiple derived classes are created from a single base class. In this type of inheritance, the base class is called parent class and the derived classes are called child classes. The child classes can have their own properties and methods in addition to the properties and methods of the parent class.

class Person { 
    public:
    string name;
    int age;

};

class Teacher : public Person{ //HIERARCHIAL INHERITANCE - Teacher and Student are derived class and Person is base class
    public:
    string subject;
};

class Student : public Person{ 
    public:
    int rollno;
};


int main(){

    Student s1;
    s1.name = "vishal";
    s1.age = 22;
    s1.rollno = 11111;

    cout<<"name : "<<s1.name<<endl;
    cout<<"age : "<<s1.age<<endl;  
    cout<<"roll number : "<<s1.rollno<<endl;

    Teacher t1;
    t1.name = "neha";
    t1.age = 30;
    t1.subject = "DSA";

    cout<<"name : "<<t1.name<<endl;
    cout<<"age : "<<t1.age<<endl;   
    cout<<"subject : "<<t1.subject<<endl;

   
   
    return 0;
}