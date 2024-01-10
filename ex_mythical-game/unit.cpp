#include "unit.hpp"
#include <algorithm>

namespace mg{


//     DrakeBurner* drake_burner_ = new DrakeBurner("DrakeBurner1");
// DwarvishFighter* dwarvish_fighter_ = new DwarvishFighter("DwarvishFighter1");
// ElvishArcher* elvish_archer_ = new ElvishArcher("ElvishArcher1");
// Unit* current_unit_;


std::vector<std::shared_ptr<Unit>> create_units(const std::string& type,int count){
    std::vector<std::shared_ptr<Unit>> created_units;
    
    if(type == "DrakeBurner"){
        for(int i = 0; i < count; i++){
            auto unit = std::make_shared<DrakeBurner>("DrakeBurner" + std::to_string(i+1));
            created_units.push_back(unit);
        }
    }

    if(type == "DwarvishFighter"){
        for(int i = 0; i < count; i++){
            auto unit = std::make_shared<DwarvishFighter>("DwarvishFighter" + std::to_string(i+1));
            created_units.push_back(unit);
        }
    }

    if(type == "ElvishArcher"){
        for(int i = 0; i < count; i++){
            auto unit = std::make_shared<ElvishArcher>("ElvishArcher" + std::to_string(i+1));
            created_units.push_back(unit);
        }
    }

    return created_units;
}

std::vector<std::shared_ptr<Unit>>  available_units(const std::vector<std::shared_ptr<Unit>>&  all,const std::vector<std::shared_ptr<Unit>>&  in_battle){
    std::vector<std::shared_ptr<Unit>>  diffrence;
    
    std::set_difference(all.begin(), all.end(), 
        in_battle.begin(), in_battle.end(),
            std::inserter(diffrence, diffrence.begin()));
    
    return diffrence;
} 

void send_to_battle(const std::vector<std::shared_ptr<Unit>>&  available,std::vector<std::shared_ptr<Unit>>&  in_battle,long unsigned int count){
    if(available.size() < count) return;
    
    for(long unsigned int i = in_battle.size(); i < count; i++)
        in_battle.push_back(available[i]);
}

} // mg

