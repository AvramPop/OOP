# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/dani/Desktop/sources/clion-2018.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dani/Desktop/sources/clion-2018.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sem2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sem2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sem2.dir/flags.make

CMakeFiles/sem2.dir/main.c.o: CMakeFiles/sem2.dir/flags.make
CMakeFiles/sem2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sem2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem2.dir/main.c.o   -c /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/main.c

CMakeFiles/sem2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/main.c > CMakeFiles/sem2.dir/main.c.i

CMakeFiles/sem2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/main.c -o CMakeFiles/sem2.dir/main.c.s

CMakeFiles/sem2.dir/Planet.c.o: CMakeFiles/sem2.dir/flags.make
CMakeFiles/sem2.dir/Planet.c.o: ../Planet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sem2.dir/Planet.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem2.dir/Planet.c.o   -c /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/Planet.c

CMakeFiles/sem2.dir/Planet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem2.dir/Planet.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/Planet.c > CMakeFiles/sem2.dir/Planet.c.i

CMakeFiles/sem2.dir/Planet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem2.dir/Planet.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/Planet.c -o CMakeFiles/sem2.dir/Planet.c.s

CMakeFiles/sem2.dir/DynamicVector.c.o: CMakeFiles/sem2.dir/flags.make
CMakeFiles/sem2.dir/DynamicVector.c.o: ../DynamicVector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sem2.dir/DynamicVector.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem2.dir/DynamicVector.c.o   -c /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/DynamicVector.c

CMakeFiles/sem2.dir/DynamicVector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem2.dir/DynamicVector.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/DynamicVector.c > CMakeFiles/sem2.dir/DynamicVector.c.i

CMakeFiles/sem2.dir/DynamicVector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem2.dir/DynamicVector.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/DynamicVector.c -o CMakeFiles/sem2.dir/DynamicVector.c.s

# Object files for target sem2
sem2_OBJECTS = \
"CMakeFiles/sem2.dir/main.c.o" \
"CMakeFiles/sem2.dir/Planet.c.o" \
"CMakeFiles/sem2.dir/DynamicVector.c.o"

# External object files for target sem2
sem2_EXTERNAL_OBJECTS =

sem2: CMakeFiles/sem2.dir/main.c.o
sem2: CMakeFiles/sem2.dir/Planet.c.o
sem2: CMakeFiles/sem2.dir/DynamicVector.c.o
sem2: CMakeFiles/sem2.dir/build.make
sem2: CMakeFiles/sem2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable sem2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sem2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sem2.dir/build: sem2

.PHONY : CMakeFiles/sem2.dir/build

CMakeFiles/sem2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sem2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sem2.dir/clean

CMakeFiles/sem2.dir/depend:
	cd /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2 /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2 /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug /home/dani/Desktop/code/faculta/an1/sem2/OOP/sem2/cmake-build-debug/CMakeFiles/sem2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sem2.dir/depend

