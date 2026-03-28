#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    double* cgpaptr; // pointer to double


    Student(string name, double cgpa){
        this->name=name;
        this->cgpaptr=new double(cgpa); // dynamically allocate memory for cgpa
    }

    Student(Student &obj){ // copy constructor
        this->name=obj.name;
        cgpaptr = new double; // allocate new memory for cgpa
        *cgpaptr = *obj.cgpaptr; // copy the value from the source object
    }
    void printInfo(){
        cout<<"the name of student is "<<name<<endl;
        cout<<"the cgpa of student is "<<*cgpaptr<<endl;

    }

//shallow copy - is a bitwise copy of an object. 
//It copies all the data members of the object as it is.
// It does not create a new memory for the data members.
// It just copies the address of the data members. So, 
//if we change the value of the data member in one object,
// it will change the value of the data member in another object as well.



//deep copy - is a copy of an object which creates a new memory for the data members.
// It copies the value of the data members to the new memory.
// It creates a new memory for the data members.
// In deep copy, if we change the value of the data member in one object,
// it will not change the value of the data member in another object as they are stored in different memory locations.


};

int main(){

    Student s1("vishal deep", 8.8);
    s1.printInfo();

    Student s2(s1);// copy constructor call

    *(s2.cgpaptr) = 9.9; // change the value of cgpa for s2

     s2.name = "neha";
     
     s2.printInfo();



    return 0;
}