# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alvin/Documents/ube_wx/to_do_app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alvin/Documents/ube_wx/to_do_app/build

# Include any dependencies generated for this target.
include CMakeFiles/unit_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unit_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unit_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit_test.dir/flags.make

CMakeFiles/unit_test.dir/task.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/task.cpp.o: ../task.cpp
CMakeFiles/unit_test.dir/task.cpp.o: CMakeFiles/unit_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvin/Documents/ube_wx/to_do_app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit_test.dir/task.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unit_test.dir/task.cpp.o -MF CMakeFiles/unit_test.dir/task.cpp.o.d -o CMakeFiles/unit_test.dir/task.cpp.o -c /home/alvin/Documents/ube_wx/to_do_app/task.cpp

CMakeFiles/unit_test.dir/task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvin/Documents/ube_wx/to_do_app/task.cpp > CMakeFiles/unit_test.dir/task.cpp.i

CMakeFiles/unit_test.dir/task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvin/Documents/ube_wx/to_do_app/task.cpp -o CMakeFiles/unit_test.dir/task.cpp.s

CMakeFiles/unit_test.dir/unit_test.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/unit_test.cpp.o: ../unit_test.cpp
CMakeFiles/unit_test.dir/unit_test.cpp.o: CMakeFiles/unit_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvin/Documents/ube_wx/to_do_app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unit_test.dir/unit_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unit_test.dir/unit_test.cpp.o -MF CMakeFiles/unit_test.dir/unit_test.cpp.o.d -o CMakeFiles/unit_test.dir/unit_test.cpp.o -c /home/alvin/Documents/ube_wx/to_do_app/unit_test.cpp

CMakeFiles/unit_test.dir/unit_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/unit_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvin/Documents/ube_wx/to_do_app/unit_test.cpp > CMakeFiles/unit_test.dir/unit_test.cpp.i

CMakeFiles/unit_test.dir/unit_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/unit_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvin/Documents/ube_wx/to_do_app/unit_test.cpp -o CMakeFiles/unit_test.dir/unit_test.cpp.s

# Object files for target unit_test
unit_test_OBJECTS = \
"CMakeFiles/unit_test.dir/task.cpp.o" \
"CMakeFiles/unit_test.dir/unit_test.cpp.o"

# External object files for target unit_test
unit_test_EXTERNAL_OBJECTS =

unit_test: CMakeFiles/unit_test.dir/task.cpp.o
unit_test: CMakeFiles/unit_test.dir/unit_test.cpp.o
unit_test: CMakeFiles/unit_test.dir/build.make
unit_test: libcatch2.a
unit_test: CMakeFiles/unit_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alvin/Documents/ube_wx/to_do_app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable unit_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit_test.dir/build: unit_test
.PHONY : CMakeFiles/unit_test.dir/build

CMakeFiles/unit_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit_test.dir/clean

CMakeFiles/unit_test.dir/depend:
	cd /home/alvin/Documents/ube_wx/to_do_app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alvin/Documents/ube_wx/to_do_app /home/alvin/Documents/ube_wx/to_do_app /home/alvin/Documents/ube_wx/to_do_app/build /home/alvin/Documents/ube_wx/to_do_app/build /home/alvin/Documents/ube_wx/to_do_app/build/CMakeFiles/unit_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit_test.dir/depend

