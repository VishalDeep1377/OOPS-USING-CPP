#include<iostream>
#include<string>
using namespace std;


class Teacher{ //blueprint for creating objects
    private: // access specifier - private, public, protected
        double salary;
    public:


    //constructor
    //NON PARAMETERIZED CONSTRUCTOR
    Teacher(){
        dept = "CSE";
    }

    //PARAMETERIZED CONSTRUCTOR
    Teacher(string name, string dept, string subject) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
    }

    //copy constructor
    Teacher(Teacher &orgobj){ //pass by reference to avoid infinite loop
        cout<<"copy constructor called "<<endl;
        this->name = orgobj.name;
        this->dept = orgobj.dept;
        this->subject = orgobj.subject;
        this->salary = orgobj.salary;

    }

    void printInfo(){
        cout<<"the name of teacher is " <<name<<endl;
        cout<<"the dept of teacher is " <<dept<<endl;
        cout<<"the subject of teacher is " <<subject<<endl;
    }



    //properties/attributes
        string name;
        string dept;
        string subject;
        

        //methods/member functions
        void changeDept(string newDept){
            dept = newDept;
        }

        //setter
    void setSalary(double newSalary){
        salary = newSalary;
    }
    //getter
    double getSalary(){
        return salary;
    }

    
    // class Account{

    //     private:
    //     double balance;
    //     string password;  // data hiding - encapsulation

    //     public:
    //     string accountID;
    //     string username;
        
    // };

};


int main(){

    Teacher t1;  //constructor call- a special member function that is called when an object of the class is created. It is used to initialize the properties of the class. If we do not define a constructor, then the compiler will create a default constructor for us.
    // t1.name = "vishal";
    // t1.dept = "CSE";
    // t1.subject = "DSA";
    // t1.setSalary(50000);
    // cout<<t1.getSalary()<<endl;
    // cout<<"name of teacher is "<<t1.name<<endl;
    // cout<<"dept of teacher is "<<t1.dept<<endl;
    // cout<<"subject of teacher is "<<t1.subject<<endl;
    // t1.changeDept("ECE");
    // cout<<"new dept of teacher is "<<t1.dept<<endl;

    // Teacher t2;
    // t2.name = "anshul";
    // t2.subject = "DSA";
    // cout<<"name of teacher is "<<t2.name<<endl;
    // cout<<"dept of teacher is "<<t2.dept<<endl;
    // cout<<"subject of teacher is "<<t2.subject<<endl;


    Teacher t3("rohan", "CSE", "CPP");
    t3.printInfo();

    Teacher t4(t3); // copy constructor call 
    t4.printInfo();


    return 0;
}