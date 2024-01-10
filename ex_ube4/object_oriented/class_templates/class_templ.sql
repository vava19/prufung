
Unfortunately, this program won’t compile, and has a number of problems that need to be addressed.

First, unlike functions, type definitions can’t be overloaded. The compiler will treat double 
second definition of Pair as an erroneous redeclaration of the first definition of Pair.
 Second, although functions can be overloaded, our max(Pair) functions only differ by return type, 
 and overloaded functions can’t be differentiated solely by return type. 
 Third, there is a lot of redundancy here. Each Pair struct is identical (except for the data type)
  and same with our max(Pair) functions (except for the return type)

  ----------------
--  this does not work:  defintions (struct) cannot be overloaded
#include <iostream>

struct Pair
{
    int first{};
    int second{};
};

struct Pair // compile error: erroneous redefinition of Pair
{
    double first{};
    double second{};
};

constexpr int max(Pair p)
{
    return (p.first < p.second ? p.second : p.first);
}

constexpr double max(Pair p) // compile error: overloaded function differs only by return type
{
    return (p.first < p.second ? p.second : p.first);
}

int main()
{
    Pair p1{ 5, 6 };
    std::cout << max(p1) << " is larger\n";

    Pair p2{ 1.2, 3.4 };
    std::cout << max(p2) << " is larger\n";

    return 0;
}
