//  pointers are just another type of data like: integer, string ...
// double work mit decimal nums, strings mit characters, pointers mit -->memory addr.
#include <iostream>
using namespace std;

int main() 
{
    int age = 20;
    double salary = 2240.34;
    string lname = "Kazaz";

    // cout << age <<endl;
    // cout << salary << endl;
    // cout << lname << endl;
    // cout << endl;

    cout << &age << endl;  // printed out memory address of "age"
    cout << &lname << endl;

    int *pAge = &age;   // want to save address, have to use *(pointer)  + datatyp   (pAge memory addr. will save "age" memory addr.)
    cout << pAge << endl;  // pointer to the addres of "age"
    cout << endl;
    cout << *pAge << endl; //derefencing  (like: **)  --> darstellt: value of "age" --> *page is equal to **pAge
    cout << &pAge << endl;  // addres not of age, but of "pAge"
    cout << *&pAge << endl;
    cout << endl;

    cout << *&salary;   // -> ist 2240.34 - value

}