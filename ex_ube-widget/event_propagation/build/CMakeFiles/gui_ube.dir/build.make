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
CMAKE_SOURCE_DIR = /home/alvin/Documents/ube_wx/event_propagation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alvin/Documents/ube_wx/event_propagation/build

# Include any dependencies generated for this target.
include CMakeFiles/gui_ube.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gui_ube.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gui_ube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gui_ube.dir/flags.make

CMakeFiles/gui_ube.dir/app.cpp.o: CMakeFiles/gui_ube.dir/flags.make
CMakeFiles/gui_ube.dir/app.cpp.o: ../app.cpp
CMakeFiles/gui_ube.dir/app.cpp.o: CMakeFiles/gui_ube.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvin/Documents/ube_wx/event_propagation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gui_ube.dir/app.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gui_ube.dir/app.cpp.o -MF CMakeFiles/gui_ube.dir/app.cpp.o.d -o CMakeFiles/gui_ube.dir/app.cpp.o -c /home/alvin/Documents/ube_wx/event_propagation/app.cpp

CMakeFiles/gui_ube.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui_ube.dir/app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvin/Documents/ube_wx/event_propagation/app.cpp > CMakeFiles/gui_ube.dir/app.cpp.i

CMakeFiles/gui_ube.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui_ube.dir/app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvin/Documents/ube_wx/event_propagation/app.cpp -o CMakeFiles/gui_ube.dir/app.cpp.s

CMakeFiles/gui_ube.dir/main_frame.cpp.o: CMakeFiles/gui_ube.dir/flags.make
CMakeFiles/gui_ube.dir/main_frame.cpp.o: ../main_frame.cpp
CMakeFiles/gui_ube.dir/main_frame.cpp.o: CMakeFiles/gui_ube.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvin/Documents/ube_wx/event_propagation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gui_ube.dir/main_frame.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gui_ube.dir/main_frame.cpp.o -MF CMakeFiles/gui_ube.dir/main_frame.cpp.o.d -o CMakeFiles/gui_ube.dir/main_frame.cpp.o -c /home/alvin/Documents/ube_wx/event_propagation/main_frame.cpp

CMakeFiles/gui_ube.dir/main_frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui_ube.dir/main_frame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvin/Documents/ube_wx/event_propagation/main_frame.cpp > CMakeFiles/gui_ube.dir/main_frame.cpp.i

CMakeFiles/gui_ube.dir/main_frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui_ube.dir/main_frame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvin/Documents/ube_wx/event_propagation/main_frame.cpp -o CMakeFiles/gui_ube.dir/main_frame.cpp.s

# Object files for target gui_ube
gui_ube_OBJECTS = \
"CMakeFiles/gui_ube.dir/app.cpp.o" \
"CMakeFiles/gui_ube.dir/main_frame.cpp.o"

# External object files for target gui_ube
gui_ube_EXTERNAL_OBJECTS =

gui_ube: CMakeFiles/gui_ube.dir/app.cpp.o
gui_ube: CMakeFiles/gui_ube.dir/main_frame.cpp.o
gui_ube: CMakeFiles/gui_ube.dir/build.make
gui_ube: CMakeFiles/gui_ube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alvin/Documents/ube_wx/event_propagation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable gui_ube"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui_ube.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gui_ube.dir/build: gui_ube
.PHONY : CMakeFiles/gui_ube.dir/build

CMakeFiles/gui_ube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gui_ube.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gui_ube.dir/clean

CMakeFiles/gui_ube.dir/depend:
	cd /home/alvin/Documents/ube_wx/event_propagation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alvin/Documents/ube_wx/event_propagation /home/alvin/Documents/ube_wx/event_propagation /home/alvin/Documents/ube_wx/event_propagation/build /home/alvin/Documents/ube_wx/event_propagation/build /home/alvin/Documents/ube_wx/event_propagation/build/CMakeFiles/gui_ube.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gui_ube.dir/depend

