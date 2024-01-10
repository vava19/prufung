
#include <iostream>
#include <string>
#include <vector>
#include "weapon.hpp"





class Unit {
public:
    Unit(const std::string& type_name, const std::string& name, uint32_t max_health, uint32_t moves)
        : type_name_(type_name), name_(name), max_health_(max_health), moves_(moves) {}

    std::string type_name() const { return type_name_; }
    std::string name() const { return name_; }
    uint32_t max_health() const { return max_health_; }
    uint32_t moves() const { return moves_; }
    const std::vector<Weapon>& weapons() const { return weapons_; }

private:
    std::string type_name_;
    std::string name_;
    uint32_t max_health_;
    uint32_t moves_;
    std::vector<Weapon> weapons_;
};
