// ranije sam se pitao kako mogu vise members gliechzeitig ändern
// Note that because we didn’t want to change joe.id, 
//we needed to provide the current value for joe.id in our list
// as a placeholder, so that memberwise assignment could assign joe.id to joe.id. 
// 

#include <iostream>
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe { 1, 32, 60000.0 };
    joe = { joe.id, 33, 66000.0 }; // Joe had a birthday and got a raise


      std::cout << joe.id << '\n'; 
      std::cout << joe.age << '\n'; 
      std::cout << joe.wage << '\n'; 

    return 0;
}