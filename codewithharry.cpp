#include <iostream>
#include <string>
using namespace std;

// f(x) = x^2 + 2
int add(int a, int b){
    cin>>a>>b;
    return a+b;
    
}

class Student{
    public:
    string name;
    int age;
    bool gender;

    Student(string name, int age, bool gender, int rollNumber){
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->rollNumber = 11;
    }
    void printInfo(){
        cout<<"the name of student is "<<name<<endl;
        cout<<"the age of student is "<<age<<endl;
        cout<<"the gender of student is "<<gender<<endl;
    }

    void getRollNumber(int rollNumber){
        cout<<"the roll number of student is "<<this->rollNumber<<endl;
    }

 private:
    int rollNumber;   
};

    // inheritance - is a feature of OOP which allows us to create a new class from an existing class. The new class is called derived class and the existing class is called base class. The derived class inherits all the properties and methods of the base class.

class Teacher : public Student
{
    public:
        int errors;
    
};



int main(){

    
    // cout<<"hello world"<<endl;
    // cout<<"Next line";
    // string vishal = "Vishal";

    // int a, b, c;
    // short sa111 = 10;
    // short _Sa = 10;
    // cout<<sa111<<endl;



    // camelcase notation
    // int marksInMaths = 90;
    // cout<<"the marks of student in maths is  " <<marksInMaths<<endl;

    // short a;
    // int b;
    // long c;
    // long long d;
    // float score = 45.32;
    // double score2 = 45.332;
    // long double score3 = 45.332123456789;
    // cout<<"the score is "<<score<<endl;
    // cout<<"the score is "<<score2<<endl;
    // cout<<"the score is "<<score3<<endl;




  // arithmetic operations 
    // int a, b;

    // cout<<"enter first number"<<endl;
    // cin>>a;

    // cout<<"enter second number"<<endl;
    // cin>>b;

    // cout<<"the sum is " <<a+b<<endl;

    // cout<<"a + b is "<<a+b<<endl;
    // cout<<"a - b is "<<a-b<<endl;
    // cout<<"a * b is "<<a*b<<endl;   
    // cout<<"a / b is "<<(float)a/b<<endl;
    // cout<<"a % b is "<<a%b<<endl;
    // cout<<"a ++ is "<<a++<<endl;
    // cout<<"a -- is "<<a--<<endl;
    // cout<<"++a is "<<++a<<endl;
    // cout<<"--a is "<<--a<<endl;


    // int age;
    // cout<<"enter your age "<<endl;
    // cin>>age;

    // if(age>150 || age<1){
    //     cout<<"invalid age" <<endl;
    // }
    // else if(age>=18){
    //     cout<<"you can vote"<<endl;
    // }
    // else{

    //     cout<<"you cannot vote "<<endl;
    // }



//  if else if else ladder

    //  int age;
    // cout<<"enter your age "<<endl;
    // cin>>age;

    // switch (age)
    // {
    // case 12:
    //     cout<<"you are 12 years old";
    //     break;
    // case 18:
    //     cout<<"you are 18 years old";
    //     break;
    // case 22:
    //     cout<<"you are 22 years old";
    //     break;
    
    
    // default:
    //     cout<<"your age is not special";
        
    // }




// while loop

    // int index = 0;
    // while(index<34)

    // {
    //     cout<<"the value of index is "<<index<<endl;
    //     index++;
    // }


// do while loop
    // do
    // {
    //     cout<<"the value of index is "<<index<<endl;
    //     index++;
    // } while (index<33);
    

// for loop

    // for(int i = 0; i < 33; i++){
    //     cout<<"the value of index is "<<i<<endl;
    // }




    // functions
    // int a, b;

    // cout<<"enter first number"<<endl;
    // cin>>a;

    // cout<<"enter second number"<<endl;
    // cin>>b;

    // cout<<"the function returned "<<add(a,b)<<endl;


    // arrays
    // 1d array
    // int arr[3] = {1, 2, 3};
    // // arr index  0  1  2
    // cout<<arr[1];

    // int marks[6];

    // for (int i = 0; i < 6; i++)
    // {
    //     cout<<"enter the marks of student "<<i<<endl;
    //     cin>>marks[ i];
    // }

    // for (int i = 0; i < 6; i++)
    // {
    //     cout<<"marks of "<<i<<"th student is "<<marks[i]<<endl;
        
    // }



    // 2d array
    // int arr2d[2][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6}
    // };
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout<<"the value at index "<<i<<" , "<<j<<" is "<<arr2d[i][j]<<endl;
    //     }
        
        
    // }

// type casting

    // int a = 343;
    // float b = 56.66;
    // cout<<(float)a/34<<endl;
    // cout<<int(b)<<endl;


// strings
//    string name = "vishal";
//    cout<<"the name is "<<name<<endl;
//    cout<<"the length name is "<<name.length()<<endl; 
//    cout<<"the name is "<<name.substr(2,3)<<endl;
//    cout<<"the name is "<<name.substr(0,3)<<endl;






// pointers - are special datatypes which stores the address of a vairable

// int a = 34;
// int* ptra;
// ptra = &a;
// cout<<"the value of a is "<<*ptra<<endl;
// cout<<"the value of a is "<<a<<endl;
// cout<<"the address of pointer is "<<ptra<<endl;
// cout<<"the address of pointer is "<<&a<<endl;
 
// float a = 34.98;
// float* ptra;
// ptra = &a;
// cout<<"the value of a is "<<*ptra<<endl;
// cout<<"the value of a is "<<a<<endl;
// cout<<"the address of pointer is "<<ptra<<endl;
// cout<<"the address of pointer is "<<&a<<endl;
 






// CLASSES AND BOJECTS

Student vishal("vishal", 22, 1,11111);
// vishal.name = "vishal";
// vishal.age = 22;
// vishal.gender = 1;

// cout<<"the name of student is "<<vishal.name<<endl;
// cout<<"the age of student is "<<vishal.age<<endl;
// cout<<"the gender of student is "<<vishal.gender<<endl;

vishal.printInfo();
vishal.getRollNumber(11111);
// cout<<vishal.rollNumber<<endl; // this will give error because roll number is private and cannot be accessed outside the class

// Student anshul("anshul", 21, 1,12);
// anshul.name= "anshul";
// anshul.age = 21;
// anshul.gender = 1;

// anshul.printInfo();
// anshul.getRollNumber(12);

return 0;
}