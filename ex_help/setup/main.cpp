#include <iostream>
#include "unit.hpp"

int main(){
    Game::DrakeBurner d1("d0");

    d1.hp();

    std::cout << d1;

    return 0;
}