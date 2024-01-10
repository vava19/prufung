
#include <iostream>

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}

// erklar:
//  ----------------------------
// Just like we use “g_” to prefix global variables, it’s common to use “s_” to prefix static (static duration) local variables.

// One of the most common uses for static duration local variables is for unique ID generators. 
// Imagine a program where you have many similar objects (e.g. a game where you’re being attacked by many zombies, 
// or a simulation where you’re displaying many triangles). If you notice a defect, 
// it can be near impossible to distinguish which object is having problems. However, 
// if each object is given a unique identifier upon creation, then it can be easier to differentiate the objects for further debugging.


// int generateID()
// {
//     static int s_itemID{ 0 };
//     return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
// }