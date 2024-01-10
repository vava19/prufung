cmake_minimum_required(VERSION 3.18)
project(tetris VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion")


find_package(wxWidgets REQUIRED COMPONENTS core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

include(CTest)



set(CPP_SRCS  # all non-main source files
  board.cpp
  shape.cpp
  tetris.cpp
)

add_executable(${PROJECT_NAME} ${CPP_SRCS})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
#add_library(catch2 catch_amalgamated.cpp)

# foreach(sourcefile ${CPP_SRCS})
#   string(REPLACE ".cpp" "_test.cpp" testfile ${sourcefile})
#   string(REPLACE ".cpp" "" testexecutable ${testfile})
#   message(STATUS "${sourcefile} + ${testfile} => ${testexecutable}")
#   add_executable(${testexecutable} ${sourcefile} ${testfile})
#   target_link_libraries(${testexecutable} catch2)
#   add_test(NAME ${testexecutable}
#            COMMAND ${testexecutable})
# endforeach()
