
/*

size_type is typically an unsigned integral type used to represent 
the size of containers, such as arrays, vectors, or strings. 
It is defined as a member type in the C++ Standard Library containers, 
like std::vector

std::vector<int>::size_type size;  // size_type is an unsigned type


*/

#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << "length: " << prime.size() << '\n'; // returns length as type `size_type` (alias for `std::size_t`)
    return 0;
}



