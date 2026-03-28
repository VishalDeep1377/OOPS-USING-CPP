#include<iostream>
#include<string>
using namespace std;


class Person{
    public:
    string name;
    int age;


};

class Student : public Person{ 
    public:
    int rollNumber;

};

class GradStudent : public Student{ // MULTILEVEL INHERITANCE - GradStudent is derived class and Student is base class and Person is base class of Student
    public:
    string researchArea;

    
};


int main(){

    GradStudent gs1;
    gs1.name = "vishal";
    gs1.age = 22;
    gs1.rollNumber = 11111;
    gs1.researchArea = "AI";
    cout<<"name : "<<gs1.name<<endl;
    cout<<"age : "<<gs1.age<<endl;  
    cout<<"roll number : "<<gs1.rollNumber<<endl;
    cout<<"research area : "<<gs1.researchArea<<endl;



   
   
    return 0;
}