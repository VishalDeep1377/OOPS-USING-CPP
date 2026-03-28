#include<iostream>
#include<string>
using namespace std;


class Person{
    public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    Person(){
        cout<<"parent constructor"<<endl;
    }
};

class Student : public Person{ //SINGLE INHERITANCE - Student is derived class and Person is base class
    public:
    int rollNumber;

    Student(string name, int age, int rollNumber): Person(name, age){ // constructor delegation - calling the constructor of the base class from the derived class
        this->rollNumber = rollNumber;
    }

    Student(){
        cout<<"child constructor"<<endl;
    }


    void printInfo(){
        cout<<"the name of student is "<<name<<endl;
        cout<<"the age of student is "<<age<<endl;
        cout<<"the roll number of student is "<<rollNumber<<endl;
    }
};


int main(){

    Student s1("vishal", 22, 11111); 
    s1.printInfo();
   
    return 0;
}