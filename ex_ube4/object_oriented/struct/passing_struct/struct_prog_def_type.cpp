
/*
                                      https://www.learncpp.com/cpp-tutorial/struct-miscellany/#google_vignette
    was das bedeutet ?
    bedeutet das user define type can be used in another user define type  --> in diesem Fall "Struct"

    When we initialize our Company, we can also initialize our Employee by using a nested initialization list.
     And if we want to know what the CEO’s salary was, we simply use the member selection operator twice
     
*/


#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Company
{
    int numberOfEmployees {};
    Employee CEO {}; // Employee is a struct within the Company struct
};

int main()
{
    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
    std::cout << myCompany.CEO.wage << '\n'; // print the CEO's wage

    return 0;
}