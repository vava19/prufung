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
include CMakeFiles/catch2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/catch2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/catch2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/catch2.dir/flags.make

CMakeFiles/catch2.dir/catch_amalgamated.cpp.o: CMakeFiles/catch2.dir/flags.make
CMakeFiles/catch2.dir/catch_amalgamated.cpp.o: ../catch_amalgamated.cpp
CMakeFiles/catch2.dir/catch_amalgamated.cpp.o: CMakeFiles/catch2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvin/Documents/ube_wx/to_do_app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/catch2.dir/catch_amalgamated.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/catch2.dir/catch_amalgamated.cpp.o -MF CMakeFiles/catch2.dir/catch_amalgamated.cpp.o.d -o CMakeFiles/catch2.dir/catch_amalgamated.cpp.o -c /home/alvin/Documents/ube_wx/to_do_app/catch_amalgamated.cpp

CMakeFiles/catch2.dir/catch_amalgamated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/catch2.dir/catch_amalgamated.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvin/Documents/ube_wx/to_do_app/catch_amalgamated.cpp > CMakeFiles/catch2.dir/catch_amalgamated.cpp.i

CMakeFiles/catch2.dir/catch_amalgamated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/catch2.dir/catch_amalgamated.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvin/Documents/ube_wx/to_do_app/catch_amalgamated.cpp -o CMakeFiles/catch2.dir/catch_amalgamated.cpp.s

# Object files for target catch2
catch2_OBJECTS = \
"CMakeFiles/catch2.dir/catch_amalgamated.cpp.o"

# External object files for target catch2
catch2_EXTERNAL_OBJECTS =

libcatch2.a: CMakeFiles/catch2.dir/catch_amalgamated.cpp.o
libcatch2.a: CMakeFiles/catch2.dir/build.make
libcatch2.a: CMakeFiles/catch2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alvin/Documents/ube_wx/to_do_app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcatch2.a"
	$(CMAKE_COMMAND) -P CMakeFiles/catch2.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/catch2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/catch2.dir/build: libcatch2.a
.PHONY : CMakeFiles/catch2.dir/build

CMakeFiles/catch2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/catch2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/catch2.dir/clean

CMakeFiles/catch2.dir/depend:
	cd /home/alvin/Documents/ube_wx/to_do_app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alvin/Documents/ube_wx/to_do_app /home/alvin/Documents/ube_wx/to_do_app /home/alvin/Documents/ube_wx/to_do_app/build /home/alvin/Documents/ube_wx/to_do_app/build /home/alvin/Documents/ube_wx/to_do_app/build/CMakeFiles/catch2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/catch2.dir/depend
