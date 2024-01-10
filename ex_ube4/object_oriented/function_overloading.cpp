//   1.  Note that a function’s return type is not used to differentiate overloaded functions. 
//   2.  muss nur verschiedene:  different parameter types   haben
//-- 3.  An overloaded function is differentiated so long as each overloaded function has a different number of parameters. 
#include <iostream>

int add(int x, int y) // Ganzzahl-Version
{
    return x + y;
}

double add(double x, double y) // Gleitkommazahlen-Version
{
    return x + y;
}

int main()
{
    
    
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    return 0;
}
