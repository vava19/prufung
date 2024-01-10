Use std::array for constexpr arrays, and std::vector for non-constexpr arrays. what are:  constexpr arrays  or  non- constexpr arrays
ChatGPT
In C++, constexpr is a keyword that indicates that the value of an object or function can be evaluated at compile time. When it comes to arrays, constexpr arrays are arrays whose size and elements are known at compile time.

Here's an example of a constexpr array:

cpp
Copy code
constexpr int size = 5;
constexpr int myArray[size] = {1, 2, 3, 4, 5};
In this case, the size of the array (size) and the array elements are known at compile time, allowing you to use constexpr to create a compile-time constant array.

On the other hand, a non-constexpr array is a regular array whose size and elements are determined at runtime. Here's an example:

cpp
Copy code
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    // ...
    return 0;
}
In this example, myVector is a dynamic array (a std::vector) whose size and elements can be determined and modified at runtime. 
It doesn't have the compile-time constant properties associated with constexpr arrays.

So, when the recommendation says to use std::array for constexpr arrays and std::vector for non-constexpr arrays, 
it's suggesting the use of std::array for arrays with known size at compile time and std::vector for arrays with dynamic sizes determined at runtime.





