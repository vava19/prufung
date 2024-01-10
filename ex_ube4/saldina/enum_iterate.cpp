#include <iostream>

enum class WeaponType {
    arcane, 
    blade, 
    cold,
    fire, 
    impact,
    pierce
};

void getWeaponType(WeaponType myWeapon) {
    switch (myWeapon) {
    case WeaponType::arcane:
        std::cout << "mocno riga arcane\n";
        break;
    case WeaponType::blade:
        std::cout << "mocno riga blade\n";
        break;
    case WeaponType::cold:
        std::cout << "mocno riga cold\n";
        break;
    case WeaponType::fire:
        std::cout << "mocno riga fire\n";
        break;
    case WeaponType::impact:
        std::cout << "mocno riga impact\n";
        break;
    case WeaponType::pierce:
        std::cout << "mocno riga pierce\n";
        break;
    default:
        break;
    }
}

int main() {
    getWeaponType(WeaponType::arcane);
    return 0;
}
