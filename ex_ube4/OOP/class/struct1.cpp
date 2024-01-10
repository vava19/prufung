/*
 Member functions are declared inside the class type definition

In the non-member example, the print() non-member function is defined outside of the Date struct, 
in the global namespace. By default, it has external linkage, 
so it could be called from other source files (with the appropriate forward declaration).
In the member example, the print() member function is declared (and in this case, 
defined) inside the Date struct definition. Because print() is declared as part of the Date, 
this tells the compiler that print() is a member function.

we put print function inside of struct

In other words, when we call today.print(), today is the implicit object, and it is implicitly passed to the print() member function.


today.print();  --> hidden this operator -- implizit  (member function)
  printDate(date);  -->  explizit  (non-member function)
*/

// Member function version
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)  --> hidden "this" operator

    return 0;
}