#include <iostream>

int getValueFromUser() 
{
    std::cout << "Enter value: \n";
    int input{};
    std::cin >>input;
    return input;
}

int main()
{
    int num {getValueFromUser()};
    std::cout << num << " doubled is: " << num * 2 << '\n';
    return 0;
}
