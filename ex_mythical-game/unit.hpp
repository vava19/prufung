#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <memory>
#include "weapon.hpp"

namespace mg { // myhtical game

class Unit {
public:
    std::string type_name() const { return type_name_; }; 
    std::string name() const { return name_; }
    uint32_t max_health() const { return max_health_; } 
    uint32_t moves() const { return moves_; }
    std::vector<Weapon> weapons() const { return weapons_;}

protected:
    explicit Unit(const std::string& name,const std::string& type_name,uint32_t max_health,uint32_t moves,const Weapon& w1,const Weapon& w2):
        name_(name),type_name_(type_name),max_health_(max_health),moves_(moves) {
            weapons_.push_back(w1);
            weapons_.push_back(w2);
        }

private:
    std::string name_;
    std::string type_name_;
    std::uint32_t max_health_;
    std::uint32_t moves_;
    std::vector<Weapon> weapons_;
};

class DrakeBurner : public Unit {
public:
    explicit DrakeBurner(const std::string& name):
        Unit(name,"Drake Burner",42,5,Weapon("claws",7,2,WeaponType::blade,false),Weapon("fire breath",6,4,WeaponType::fire,true)) {}

};

class DwarvishFighter : public Unit {
public:
    explicit DwarvishFighter(const std::string& name):
        Unit(name,"Dwarvish Fighter",38,4,Weapon("axe",7,3,WeaponType::blade,false),Weapon("hammer",8,2,WeaponType::impact,false)) {}


};

class ElvishArcher : public Unit {
public:
    explicit ElvishArcher(const std::string& name):
        Unit(name,"Elvish Archer",29,6,Weapon("sword",5,2,WeaponType::blade,false),Weapon("bow",5,4,WeaponType::pierce,true)) {}

};

std::vector<std::shared_ptr<Unit>> create_units(const std::string& type,int count);
std::vector<std::shared_ptr<Unit>>  available_units(const std::vector<std::shared_ptr<Unit>>&  all,const std::vector<std::shared_ptr<Unit>>&  in_battle); 
void send_to_battle(const std::vector<std::shared_ptr<Unit>>&  available,std::vector<std::shared_ptr<Unit>>&  in_battle,uint64_t count);

} // mg namespace


