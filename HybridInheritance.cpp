#include<iostream>
using namespace std;

//HYBRID INHERITANCE - is a type of inheritance in which a derived class is created from two or more base classes. In this type of inheritance, the derived class inherits the properties and methods of all the base classes. The derived class can also have its own properties and methods in addition to the properties and methods of the base classes.

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


class TA : public Teacher{ // MULTILEVEL INHERITANCE - GradStudent is derived class and Student is base class and Person is base class of Student
    public:
    string course;
    int experience;
};

class GradStudent : public Student{ // MULTILEVEL INHERITANCE - GradStudent is derived class and Student is base class and Person is base class of Student
    public:
    string researchArea;

    
};


int main(){
    GradStudent gs1;

    gs1.name = "vishal";
    gs1.age = 22;
    gs1.rollno = 11111;
    gs1.researchArea = "AI";
    cout<<"name : "<<gs1.name<<endl;
    cout<<"age : "<<gs1.age<<endl;
    cout<<"roll number : "<<gs1.rollno<<endl;
    cout<<"research area : "<<gs1.researchArea<<endl;
    TA ta1;
    ta1.name = "neha";
    ta1.age = 30;
    ta1.subject = "DSA";
    ta1.course = "CPP";
    ta1.experience = 2;

    cout<<"name : "<<ta1.name<<endl;
    cout<<"age : "<<ta1.age<<endl;
    cout<<"subject : "<<ta1.subject<<endl;
    cout<<"course : "<<ta1.course<<endl;
    cout<<"experience : "<<ta1.experience<<endl;

   
   
    return 0;
}
    