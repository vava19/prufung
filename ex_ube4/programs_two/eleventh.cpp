#include <iostream>

int main() 
{
    std::cout << "Enter integer number: " << '\n';
    int numb{};
    std::cin >>numb;

    if(numb > 0) {
        if((numb % 2) == 0) {
            std::cout << numb << " is a positive and even number\n";
        } else {
            std::cout << numb << " is a positive and add number\n";
        }
    }
}