#include<iostream>
using namespace std;

//STATIC KEYWORD - is a keyword which is used to declare a static variable or a static function. A static variable is a variable which is shared by all the objects of a class. A static function is a function which can be called without creating an object of the class. A static variable is initialized only once and its value is shared by all the objects of the class. A static function can only access static variables and can only call other static functions.

void fun(){
    static int x = 0;//initialized only once and its value is shared by all the calls to the function
    cout<<"the value of x is "<<x<<endl;
    x++;
}
int main(){
    fun();
    fun();
    fun();

   


    return 0;

}