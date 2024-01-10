
/*
    check constructor , and contructor ruf
    --> sa jednim ili 2 args, default args..

*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{

public:

    Employee(std::string_view name, int id = 0) // default argument for id
        : m_name{ name }, m_id{ id }
    {
        std::cout << "Employee " << m_name << " created\n";
    }
    
private:
    std::string m_name{};
    int m_id{ 0 }; // default member initializer
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}