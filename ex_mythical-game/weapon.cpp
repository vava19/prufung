#include "weapon.hpp"

namespace mg { //mythical games

std::string Weapon::type() const {
    switch(type_){
        case WeaponType::arcane: return "arcane";
        case WeaponType::blade: return "blade";
        case WeaponType::cold: return "cold";
        case WeaponType::fire: return "fire";
        case WeaponType::impact: return "impact";
        case WeaponType::pierce: return "pierce";
        case WeaponType::none: return "none";
        default: return "";
    }
} 

// std::ostream& operator<<(std::ostream& out, const Weapon& weapon){
//     out << weapon.name() << " " << weapon.damage() << "x" << weapon.strikes() << " " << weapon.is_ranged() << " " << weapon.type();
//     return out;
// }


} // namespace mg