#include <iostream>

int main()
{
    char c { 'a' };
    std::cout << c << "  " << static_cast<int>(c) << '\n'; // prints a 97

    return 0;
}