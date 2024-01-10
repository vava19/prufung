
/*

size_type is typically an unsigned integral type used to represent 
the size of containers, such as arrays, vectors, or strings. 
It is defined as a member type in the C++ Standard Library containers, 
like std::vector

std::vector<int>::size_type size;  // size_type is an unsigned type (just positive numbers)

use of static_cast<int>(prime.size()) in your previous example 
is for explicitly converting the unsigned type (size_type) to a signed type (int).

*/

#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    int length { static_cast<int>(prime.size()) }; // static_cast return value to int
    std::cout << "length: " << length ;

    return 0;
}