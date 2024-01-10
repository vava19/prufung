cmake_minimum_required(VERSION 3.18)
project(mythical_game VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include(CTest)

set(CPP_SRCS  # all non-main, non-GUI source files
  unit.cpp
  weapon.cpp
)

set(GUI_SRCS
  app.cpp 
  mythical_game.cpp
)

find_package(wxWidgets REQUIRED COMPONENTS net core base adv) #adv for grid
include(${wxWidgets_USE_FILE})
add_executable(${PROJECT_NAME} ${GUI_SRCS} ${CPP_SRCS})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

add_library(catch2 catch_amalgamated.cpp)

add_executable(unit_test unit.cpp  unit_test.cpp) 
target_link_libraries(unit_test catch2)
add_test(NAME unit_test COMMAND unit_test)


# g++ std=c++20 -Wall -Wextra app.cpp mythical_game.cpp unit.cpp weapon.cpp -o mythical_game
