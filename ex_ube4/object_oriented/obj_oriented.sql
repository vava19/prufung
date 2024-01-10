

--------- FUNCTION OVERLAODING -----------------
Function overloading allows us to create multiple functions with the same name,
 so long as each identically named function has different parameter types 
 (or the functions can be otherwise differentiated). 
 Each function sharing a name (in the same scope) is called an overloaded function 
 ---------------

 int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int main()
{
    return 0;
}


---
The above program will compile. Although you might expect these functions to result in a naming conflict, 
that is not the case here. Because the parameter types of these functions differ, 
the compiler is able to differentiate these functions, and will treat them as separate functions that just happen to share a name.


------  overloaded function:
//   Note that a function’s return type is not used to differentiate overloaded functions. 
//   muss nur verschiedene:  different parameter types   haben


-----------------------------------
--   An overloaded function is differentiated so long as each overloaded function has a different number of parameters. 
 For example:
----------------
int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

-------------------------------

Overloading based on type of parameters

A function can also be differentiated so long as each overloaded function’s list of parameter types is distinct. 
For example, all of the following overloads are differentiated:

int add(int x, int y); // integer version
double add(double x, double y); // floating point version
double add(int x, double y); // mixed version
double add(double x, int y); // mixed version


---------------------------------

----------- FUNCTION TEMPLATE  --------------

Function templates

A function template is a function-like definition that is used to generate one or more overloaded functions, 
each with a different set of actual types. This is what will allow us to create
 functions that can work with many different types.

 --------




  --- pas by value   --- pass by reference -----

  Here’s the same example as above, using pass by reference instead of pass by value:

  ------------------

#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}



-----
When to pass by (const) reference
Because class types can be expensive to copy (sometimes significantly so),
 class types are usually passed by const reference instead of by value to
  avoid making an expensive copy of the argument. Fundamental types are cheap to copy,
   so they are typically passed by value.

   ----

   Best practice

As a rule of thumb, pass fundamental types by value, and class (or struct) types by const reference.

Other common types to pass by value: enumerated types and std::string_view.
Other common types to pass by (const) reference: std::string, std::array, and std::vector.


---

Best practice

Prefer pass by value for objects that are cheap to copy,
 and pass by const reference for objects that are expensive to copy. 
 If you’re not sure whether an object is cheap or expensive to copy, 
 favor pass by const reference.

 ----------------

 referencing:
 ---
int main()
{
    char x {}; // assume this is assigned memory address 140
    char& ref { x }; // ref is an lvalue reference to x (when used with a type, & means lvalue reference)

    return 0;
}
-----
Because ref acts as an alias for x, whenever we use ref, 
the program will go to memory address 140 to access 
the value. Again the compiler takes care of the addressing, 
so that we don’t have to think about it.

-------------

Tip

The & symbol tends to cause confusion because it has different meanings depending on context:

When following a type name, & denotes an lvalue reference: int& ref.
When used in a unary context in an expression, & is the address-of operator: std::cout << &x.
When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.

----------
--- OVO JE CORE  od pointer i reference ponasanje:
--      https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

#include <iostream>

int main()
{
    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

    return 0;
}
--Ergebnis:
This program prints:

555
666
777


-------------------





