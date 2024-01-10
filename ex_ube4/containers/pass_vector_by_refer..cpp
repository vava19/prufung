/*
With a std::vector, the element type is part of the type information of the object.
 Therefore, when we use a std::vector as a function parameter, 
 we have to explicitly specify the element type:

*/


#include <iostream>
#include <vector>

void passByRef(const std::vector<int>& arr) // we must explicitly specify <int> here
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes);

    return 0;
}