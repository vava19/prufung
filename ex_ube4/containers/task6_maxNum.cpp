
/*
   Write a function template to find the largest value in an std::vector.

The following code should execute:

#include <iostream>
#include <vector>

int main()
{
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92

    return 0;
}

*/


#include <iostream>
#include <vector>

template <typename T>
T findMax(const std::vector<T>& arr)
{
    std::size_t length { arr.size() };

    T max { 0 };
    for (std::size_t index{ 0 }; index < length; ++index) // iterate through all the elements
        if (arr[index] > max)                             // if the current element is greater than our prior max
            max = arr[index];                             // we found a new max

    return max;
}

int main()
{
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::cout << "The max score is: " << findMax(testScore) << '\n';

    return 0;
}