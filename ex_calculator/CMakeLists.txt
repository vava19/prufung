cmake_minimum_required(VERSION 3.18)
project(calc VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion")
include(CTest)

set(CPP_SRCS
  app.cpp
  simple_calculator.cpp
  calc_ui.cpp
)

set(TEST_SRCS
  app_test.cpp
  simple_calculator_test.cpp
  # calc_ui_test.cpp
)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE)
  include(${wxWidgets_USE_FILE})
endif()

add_executable(calc ${CPP_SRCS})
target_link_libraries(calc PUBLIC ${wxWidgets_LIBRARIES})

# testing part

add_library(catch2 catch_amalgamated.cpp)

foreach(sourcefile ${TEST_SRCS})
  string(REPLACE "_test.cpp" "" testexecutable ${sourcefile})
  message(STATUS "${testexecutable}_test.cpp => ${testexecutable}")
  add_executable(${testexecutable} ${sourcefile} ${CPP_SRCS})
  target_link_libraries(${testexecutable} catch2)
  add_test(NAME ${testexecutable}
           COMMAND ${testexecutable})
endforeach()
