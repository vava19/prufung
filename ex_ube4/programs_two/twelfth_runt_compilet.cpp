// runtime   vs compile time
//  Even though y has a const qualifier, the initialization value (the return value of getNumber())
// isn’t known until runtime. Thus, y is a runtime constant, not a compile-time constant. 
//And because y is a runtime constant, evaluation of y must be done at runtime, so the expression x + y is also a runtime expression.

// x is a compile-time constant because its value is known at compile time. y, on the other hand,
// is a runtime constant because its value is determined during the execution of the program based on user input.


#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}

int main()
{
    const int x { 3 };           // x is a compile time constant

    const int y { getNumber() }; // y is a runtime constant

    const int z { x + y };       // x + y is a runtime expression, so z is a runtime const

    return 0;
}