
// Global variables can also be defined inside a user-defined namespace. Here is the same example as above,
// but g_x has been moved from the global scope into user-defined namespace Foo:
//  Best practice
//Consider using a “g” or “g_” prefix when naming non-const global variables, to help differentiate them from local variables and function parameter


#include <iostream>

namespace Foo // Foo is defined in the global scope
{
    int g_x {}; // g_x is now inside the Foo namespace, but is still a global variable
}

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    Foo::g_x = 3;
    std::cout << Foo::g_x << '\n';
}

int main()
{
    doSomething();
    std::cout << Foo::g_x << '\n';

    // global variables can be seen and used everywhere in the file
    Foo::g_x = 5;
    std::cout << Foo::g_x << '\n';

    return 0;
}