#include<iostream>
using namespace std;

    class Teacher{
    private:
        double salary;
    public:
    
    string name;
    string dept;
    string subject;
    
    //PARAMETERIZED CONSTRUCTOR
    Teacher(string name, string dept, string subject){
        this->name = name; // this is a pointer which points to the current object
        this->dept = dept;
        this->subject = subject;
    }
    void printInfo(){
        cout<<"the name of teacher is "<<name<<endl;
        cout<<"the dept of teacher is "<<dept<<endl;
        cout<<"the subject of teacher is "<<subject<<endl;
    }
   
};
int main(){
    Teacher t1("vishal", "MCA", "JAVA");
    t1.printInfo();
    

    //copy constructor - is a constructor which is used to create a new object from an existing object. 
    //The new object is called copy object and the existing object is called original object. 
    //The copy constructor is used to copy the values of the data members of the original object to the copy object.

    Teacher t2(t1); // default copy constructor call
    t2.printInfo();

    //pointers - are special datatypes which stores the address of a vairable
    //types of pointers - int pointer, float pointer, char pointer, double pointer, void pointer
    // derefrencing operater - * (asterisk) is used to get the value of the address stored in the pointer
    int x =10; 
    int*ptr=&x;
    cout<<"the address of x is "<<ptr<<endl;    
    return 0;
}