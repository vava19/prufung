// verlegich mit file "pass_by_value"

#include <iostream>

int addOne(int& y) // y is a reference
{
    ++y; // this modifies the  original x object 
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