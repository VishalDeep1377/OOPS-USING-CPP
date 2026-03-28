#include<iostream>
#include<string>
using namespace std;



class Student { 
    public:
    string name;
    int rollNumber;

};

class Teacher : public Student{ // MULTILEVEL INHERITANCE - GradStudent is derived class and Student is base class and Person is base class of Student
    public:
    string subject;
    double salary;
};

class TA : public Teacher{ // MULTILEVEL INHERITANCE - GradStudent is derived class and Student is base class and Person is base class of Student
    public:
    string course;
    int experience;
};


int main(){

    TA ta1;
    ta1.name = "vishal";
    ta1.rollNumber = 11111;

    ta1.subject = "DSA";
    ta1.salary = 50000;
    
    ta1.course = "CPP";
    ta1.experience = 2;

    cout<<"name : "<<ta1.name<<endl;
    cout<<"roll number : "<<ta1.rollNumber<<endl;

    cout<<"subject : "<<ta1.subject<<endl;
    cout<<"salary : "<<ta1.salary<<endl;

    cout<<"course : "<<ta1.course<<endl;
    cout<<"experience : "<<ta1.experience<<endl;



   
   
    return 0;
}