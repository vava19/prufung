/*
    multiple template types

    To define multiple template types, in our template 
    parameter declaration, we separate each of our 
    desired template types with a comma. In the above 
    example we define two different template types, 
    one named T, and one named U.
     The actual template type arguments for T and U 
     can be different (as in the case of p1 and p2 above)
      or the same (as in the case of p3).
*/

#include <iostream>

template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

template <typename T, typename U>
void print(Pair<T, U> p)
{
    std::cout << '[' << p.first << ", " << p.second << ']';
}

int main()
{
    Pair<int, double> p1{ 1, 2.3 }; // a pair holding an int and a double
    Pair<double, int> p2{ 4.5, 6 }; // a pair holding a double and an int
    Pair<int, int> p3{ 7, 8 };      // a pair holding two ints

    print(p2);

    return 0;
}