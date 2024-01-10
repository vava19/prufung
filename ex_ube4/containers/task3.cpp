/*
What we can do with arrays and loops

Now that we know how to traverse a container of elements using a loop, 
let’s look at the most common things that we can use container traversal for. 
We typically traverse a container in order to do one of four things:

Calculate a new value based on the value of existing elements (e.g. average value, sum of values).
Search for an existing element (e.g. has exact match, count number of matches, find highest value).
Operate on each element (e.g. output each element, multiply all elements by 2).
Reorder the elements (e.g. sort the elements in ascending order)

-------------------------------------
Question #1

Write a short program that prints the elements of the
 following vector to the screen using a loop:

#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    // Add your code here

    return 0;
}

*/


#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    std::size_t length { arr.size() };

    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << arr[index] << ' ';
    }

    std::cout << '\n';

    return 0;
}


