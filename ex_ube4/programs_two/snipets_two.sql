How parameters and arguments work together
-----
When a function is called, all of the parameters of the function are created as variables,
 and the value of each of the arguments is copied into the matching parameter (using copy initialization). 
 This process is called pass by value. Function parameters that utilize pass by value are called value parameters.

 ---------------------------------

 

 #include <iostream>

int main()
{
    constexpr bool inBigClassroom { false };

    if (inBigClassroom)
        constexpr int classSize { 30 };
    else
        constexpr int classSize { 20 };

    std::cout << "The class size is: " << classSize;

    return 0;
}


However, this won’t compile, and you’ll get an error message that classSize isn’t defined. 
Much like how variables defined inside functions die at the end of the function, 
variables defined inside an if-statement or else-statement die at the end of the if-statement or else-statement. 
Thus, classSize has already been destroyed by the time we try to print it.


-------correkt version of aboce example:

#include <iostream>

int getClassSize(bool inBigClassroom)
{
    if (inBigClassroom)
        return 30;
    else
        return 20;
}

int main()
{
    const int classSize { getClassSize(false) };
    std::cout << "The class size is: " << classSize;

    return 0;
}
--- noch besser 

#include <iostream>

int main()
{
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';

    return 0;
}

-------
return isStunned ? 0 : movesLeft;           // not used in compound expression, condition contains no operators
int z { (x > y) ? x : y };                  // not used in compound expression, condition contains operators
std::cout << (isAfternoon() ? "PM" : "AM"); // used in compound expression, condition contains no operators (function call operator excluded)
std::cout << ((x > y) ? x : y);             // used in compound expression, condition contains operators




--------------------------
void someFunction(int x)
{
    int x{}; // compilation failure due to name collision with function parameter
}

int main()
{
    return 0;
}
---
-- The above program doesn’t compile because the variable x defined inside the function body
--  and the function parameter x have the same name and both are in the same block scope.

--    Local variables have no linkage, which means that each declaration refers to a unique object. For example:

int main()
{
    int x { 2 }; // local variable, no linkage

    {
        int x { 3 }; // this identifier x refers to a different object than the previous x
    }

    return 0;
}


------------------
    If a variable is needed in an outer block, it needs to be declared in the outer block:

--


#include <iostream>

int main()
{
    int y { 5 }; // we re declaring y here because we need it in this outer block later

    {
        int x{};
        std::cin >> x;

        // if we declared y here, immediately before its actual first use...
        if (x == 4)
            y = 4;
    } // ... it would be destroyed here

    std::cout << y; // and we need y to exist here

    return 0;
}

---------

Unlike local variables, which are uninitialized by default, variables with static duration are zero-initialized by default.
Non-constant global variables can be optionally initialized:
--
int g_x;       // no explicit initializer (zero-initialized by default)
int g_y {};    // value initialized (resulting in zero-initialization)
int g_z { 1 }; // list initialized with specific value

--  --
Just like local variables, global variables can be constant. As with all constants, constant global variables must be initialized.

----    Quick Summary   ---------------------------------------------

// Non-constant global variables
int g_x;                 // defines non-initialized global variable (zero initialized by default)
int g_x {};              // defines explicitly value-initialized global variable
int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global const

// Constexpr global variables
constexpr int g_y;       // error: constexpr variables must be initialized
constexpr int g_y { 3 }; // defines initialized global constexpr

------------------------------------------------------------------------------------------
-- Global variable and functions identifiers can have either internal linkage or external linkage.

-- INTERNAL LOCAL LINKAGE --
-- Quick Summary 

-- To make a non-constant global variable internal, we use the static keyword

#include <iostream>

static int g_x{}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

const int g_y{ 1 }; // const globals have internal linkage by default
constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;
}
-----

// Internal global variables definitions:
static int g_x;          // defines non-initialized internal global variable (zero initialized by default)
static int g_x{ 1 };     // defines initialized internal global variable

const int g_y { 2 };     // defines initialized internal global const variable
constexpr int g_y { 3 }; // defines initialized internal global constexpr variable

// Internal function definitions:
static int foo() {};     // defines internal function
-----


-- The most commonly used storage class specifiers are static, extern, and mutable. The term storage class specifier is mostly used in technical documentations.

--- exerrnal vaiable und function
-- function per default ->  external  == we can limit mit "static"
-- non-const variable per default external == limit mit "static"
const variable  --> inernal linkage per default ==> external kann sein mit: "extern"