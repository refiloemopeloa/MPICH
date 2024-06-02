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
CMAKE_SOURCE_DIR = "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/reduce_min_array.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/reduce_min_array.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/reduce_min_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reduce_min_array.dir/flags.make

CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o: CMakeFiles/reduce_min_array.dir/flags.make
CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o: ../reduce_min_array.c
CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o: CMakeFiles/reduce_min_array.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o"
	mpicc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o -MF CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o.d -o CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o -c "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/reduce_min_array.c"

CMakeFiles/reduce_min_array.dir/reduce_min_array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reduce_min_array.dir/reduce_min_array.c.i"
	mpicc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/reduce_min_array.c" > CMakeFiles/reduce_min_array.dir/reduce_min_array.c.i

CMakeFiles/reduce_min_array.dir/reduce_min_array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reduce_min_array.dir/reduce_min_array.c.s"
	mpicc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/reduce_min_array.c" -o CMakeFiles/reduce_min_array.dir/reduce_min_array.c.s

# Object files for target reduce_min_array
reduce_min_array_OBJECTS = \
"CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o"

# External object files for target reduce_min_array
reduce_min_array_EXTERNAL_OBJECTS =

reduce_min_array: CMakeFiles/reduce_min_array.dir/reduce_min_array.c.o
reduce_min_array: CMakeFiles/reduce_min_array.dir/build.make
reduce_min_array: /usr/lib/x86_64-linux-gnu/libmpich.so
reduce_min_array: CMakeFiles/reduce_min_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable reduce_min_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reduce_min_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reduce_min_array.dir/build: reduce_min_array
.PHONY : CMakeFiles/reduce_min_array.dir/build

CMakeFiles/reduce_min_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reduce_min_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reduce_min_array.dir/clean

CMakeFiles/reduce_min_array.dir/depend:
	cd "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/cmake-build-debug" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/cmake-build-debug" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3008A - PC/Side Quests/MPI/MPICH/Collective communication/Reduce MPI_MIN array/cmake-build-debug/CMakeFiles/reduce_min_array.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/reduce_min_array.dir/depend
