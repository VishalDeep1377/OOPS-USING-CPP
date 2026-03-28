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



    //destructor - is a special member function which is used to destroy the object. 
    // It is called automatically when the object goes out of scope or when the object is explicitly deleted. 
    //The destructor is used to free the memory allocated for the object and to perform any cleanup operations.

    ~Student(){
        cout<<"hii i am destructor i deleted everything"<<endl;
        delete cgpaptr; // free the memory allocated for cgpa
    } //memory leak - is a situation where the memory allocated for an object is not freed and memory will waste so we use dest.....
 
    void printInfo(){
        cout<<"the name of student is "<<name<<endl;
        cout<<"the cgpa of student is "<<*cgpaptr<<endl;

    }

};

int main(){
    Student s1("vishal deep", 8.8);
    s1.printInfo();


    return 0;
}