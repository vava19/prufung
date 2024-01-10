#include "unit.hpp"
#include "catch_amalgamated.hpp"
#include <vector>

TEST_CASE("Create new units","[create]"){
    
    auto created_units = mg::create_units("DrakeBurner",100);
    
    SECTION("created 100 DrakeBurner's")
    {
        REQUIRE(created_units.size() == 100);
        CHECK(created_units[0]->type_name() == "Drake Burner");
    }

}

TEST_CASE("Send units to battle","[battle]"){
    
    auto created_units = mg::create_units("DrakeBurner",200);
    std::vector<std::shared_ptr<mg::Unit>> in_battle;

    mg::send_to_battle(created_units,in_battle,150);
    
    SECTION("Send 150 units to battle")
    {
        REQUIRE(created_units.size() == 200);
        CHECK(in_battle.size() == 150);
    }

}

TEST_CASE("Check available units","[available]"){
    
    std::vector<std::shared_ptr<mg::Unit>> in_battle;
    auto created_units = mg::create_units("DrakeBurner",1000);
    
    SECTION("100 available units")
    {
        mg::send_to_battle(created_units,in_battle,900);
        CHECK(mg::available_units(created_units,in_battle).size() == 100);
    }

    SECTION("0 available units")
    {
        mg::send_to_battle(created_units,in_battle,1000);
        CHECK(mg::available_units(created_units,in_battle).size() == 0);
    }

    SECTION("all units available")
    {
        mg::send_to_battle(created_units,in_battle,0);
        CHECK(mg::available_units(created_units,in_battle).size() == 1000);
    }

    SECTION("sending to much units,all units should be available")
    {
        mg::send_to_battle(created_units,in_battle,INT16_MAX);
        CHECK(mg::available_units(created_units,in_battle).size() == 1000);
    }
}