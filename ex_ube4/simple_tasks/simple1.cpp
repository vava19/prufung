// range beween user enter integer und 1:
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    // oops, we used operator> instead of operator<
    for (int count{ 1 }; count < x; ++count)
    {
        std::cout << count << ' ';
    }

    std::cout << '\n';

    return 0;
}