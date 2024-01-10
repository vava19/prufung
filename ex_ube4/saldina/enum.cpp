#include <iostream>



enum class WeaponType{
    arcane, 
    blade, 
    cold,
    fire, 
    impact,
    pierce
};



int main( )
{

    int userInput;
    std::cout << "enter type of weapon as interger: " << '\n';
    std::cin >> userInput;

    WeaponType megamon;
    megamon =(WeaponType)userInput;

    switch (megamon)
    {
    case WeaponType::arcane:
        std::cout << "mocno riga arcane";
        break;
        case WeaponType::blade:
        std::cout << "mocno riga blad";
        break;
        case WeaponType::cold:
        std::cout << "mocno riga  cold";
        break;
        case WeaponType::fire:
        std::cout << "mocno riga fire";
        break;
        case WeaponType::impact:
        std::cout << "mocno riga impact";
        break;
        case WeaponType::pierce:
        std::cout << "mocno riga pierce";
        break;
    
    default:
        break;
    }



}