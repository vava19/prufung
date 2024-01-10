#include <iostream>
#include <string>
#include <vector>


enum class WeaponType {
    Melee,
    Ranged
};

class Weapon {
public:
    Weapon(const std::string& name, uint32_t damage, uint32_t strikes, WeaponType type)
        : name_(name), damage_(damage), strikes_(strikes), type_(type) {}

    bool is_ranged() const { return type_ == WeaponType::Ranged; }
    uint32_t damage() const { return damage_; }
    uint32_t strikes() const { return strikes_; }
    WeaponType type() const { return type_; }

private:
    std::string name_;
    uint32_t damage_;
    uint32_t strikes_;
    WeaponType type_;
};