/*
Initialize a std::vector with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. 
Then print the length of the array (use std::size()). 
Finally, print the value of the element with index 1 using 
the subscript operator and the at() member function.




Question #2

a) What is size_type and what is it used for?

Hide Solution

size_type is a nested typedef that is an alias for the type used to store the length (and indices, if supported) of a standard library container.

b) What type does size_type default to? Is it signed or unsigned?

Hide Solution

std::size_t, which is an unsigned type.

c) Which functions to get the length of a container return size_type?

Hide Solution

The size() member function and std::size both return size_type.



*/

#include <iostream>
#include <vector>

int main()
{
    std::vector arr { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The array has " << std::size(arr) << " elements.\n";
    std::cout << arr[1] << arr.at(1) << '\n';

    return 0;
}

