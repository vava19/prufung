#pragma once
#include <iostream>
#include <string>

namespace mg {
    
enum class WeaponType{
    arcane,
    blade,
    cold,
    fire,
    impact,
    pierce,
    none,
};

class Weapon{
public:
    Weapon();
    explicit Weapon(const std::string& name ,uint32_t damage,uint32_t strikes, WeaponType type,bool is_ranged):
        name_(name),damage_(damage),strikes_(strikes),type_(type),is_ranged_(is_ranged) {}

    uint32_t damage() const{ return damage_; }
    uint32_t strikes() const { return strikes_; }
    std::string type() const;
    std::string name() const { return name_; }
    std::string is_ranged() const { return is_ranged_ ? "ranged" : "melee";}

private:
    std::string name_;
    uint32_t damage_;
    uint32_t strikes_;
    WeaponType type_;
    bool is_ranged_;
};

//std::ostream& operator<<(std::ostream& out, WeaponType type);
//std::ostream& operator<<(std::ostream& out, const Weapon& weapon);

}