#include<iostream>
#include<string>
using namespace std;
//OPERATOR OVERLOADING - is a feature of OOP which allows us to use the same operator for different types of data. In C++, we can overload operators by defining a function with the same name as the operator and by using the keyword operator followed by the operator symbol.
//simple example of operator overloading

struct Number
{
    int value;

    Number(int v)
    {
        value = v;
    }

    // Overload + operator
    Number operator+(const Number &n)
    {
        return Number(value + n.value);
    }

    void display()
    {
        cout << value << endl;
    }
};

int main()
{
    Number n1(5), n2(10);
    Number n3 = n1 + n2;
    n3.display();


return 0;
}