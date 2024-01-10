// When an object is passed by value, the function parameter receives
// a copy of the argument. This means that any changes to the value of
// the parameter are made to the copy of the argument, not the argument itself:

#include <iostream>

int addOne(int y) // y is a copy of x
{
    ++y; // this modifies the copy of x, not the actual object x
    return y;
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

      std::cout << addOne(x) << '\n';

    std::cout << "value = " << x << '\n'; // x has not been modified

    return 0;
}