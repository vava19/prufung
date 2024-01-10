
/*

Question #1

Write a class named Ball. Ball should have two private member variables, 
one to hold a color (default value: black), and one to hold a radius 
(default value: 10.0). Add 4 constructors, 
one to handle each case below:

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}


*/

#include <iostream>
#include <string>
#include <string_view>

class Ball
{

public:
	// Default constructor (color and radius will use default value)
	Ball()
	{
            print();
	}

	// Constructor with only radius parameter (color will use default value)
	Ball(double radius)
		: m_radius{ radius }
	{
            print();
	}

	// Constructor with only color parameter (radius will use default value)
	Ball(std::string_view color)
		: m_color{ color }
	{
            print();
	}

	// Constructor with both color and radius parameters
	Ball(std::string_view color, double radius)
		: m_color{ color }
		, m_radius{ radius }
	{
            print();
	}

    void print()
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }

private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}