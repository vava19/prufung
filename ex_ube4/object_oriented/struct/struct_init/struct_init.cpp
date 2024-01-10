// struct agregate initialization

// razlike u init variabli: {} --> init: 0
// missing init ali i dalje radi jer {}= 0
// joe.wage wasn’t given an explicit initializer, it will be value-initialized to 0.0.

#include <iostream>
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe { 2, 28 }; // joe.wage will be value-initialized to 0.0
                            // advantage - mozemo i dalje uspostaviti objekat, jer je init
    
        std::cout << joe.id << '\n';  
    return 0;
}


// Fazit:
//   This means we can use an empty initialization list to value-initialize all members of the struct:
#if 0:
   Employee joe {}; // value-initialize all members
#endif;