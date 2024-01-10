
/*

Member initialization via a member initialization list

To have a constructor initialize members, we do so using a member 
initializer list (often called a “member initialization list”). 
Do not confuse this with the similarly named “initializer list” 
that is used to initialize aggregates with a list of values.
The member initializer list is defined after the constructor parameters.
 It begins with a colon (:), and then lists each member to
  initialize along with the initialization value for that variable, 
  separated by a comma. 

kod structa smo imali agregate init. jer su svi "public" i
nema constructa
*/

#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
        : m_x { x }, m_y { y } // here's our member initialization list
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}