# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/meng/CLionProjects/Json

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/meng/CLionProjects/Json/cmake-build-debug

# Include any dependencies generated for this target.
include third/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include third/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include third/googletest/CMakeFiles/gtest.dir/flags.make

third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: third/googletest/CMakeFiles/gtest.dir/flags.make
third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../third/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meng/CLionProjects/Json/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/meng/CLionProjects/Json/third/googletest/src/gtest-all.cc

third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/meng/CLionProjects/Json/third/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/meng/CLionProjects/Json/third/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f third/googletest/CMakeFiles/gtest.dir/build.make third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

third/googletest/libgtest.a: third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
third/googletest/libgtest.a: third/googletest/CMakeFiles/gtest.dir/build.make
third/googletest/libgtest.a: third/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/meng/CLionProjects/Json/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third/googletest/CMakeFiles/gtest.dir/build: third/googletest/libgtest.a

.PHONY : third/googletest/CMakeFiles/gtest.dir/build

third/googletest/CMakeFiles/gtest.dir/requires: third/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : third/googletest/CMakeFiles/gtest.dir/requires

third/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : third/googletest/CMakeFiles/gtest.dir/clean

third/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/meng/CLionProjects/Json/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/meng/CLionProjects/Json /home/meng/CLionProjects/Json/third/googletest /home/meng/CLionProjects/Json/cmake-build-debug /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest /home/meng/CLionProjects/Json/cmake-build-debug/third/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third/googletest/CMakeFiles/gtest.dir/depend

