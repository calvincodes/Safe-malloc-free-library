# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anshu/Project/malloc-library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anshu/Project/malloc-library/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/malloc_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/malloc_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloc_library.dir/flags.make

CMakeFiles/malloc_library.dir/main.c.o: CMakeFiles/malloc_library.dir/flags.make
CMakeFiles/malloc_library.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anshu/Project/malloc-library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/malloc_library.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_library.dir/main.c.o   -c /Users/anshu/Project/malloc-library/main.c

CMakeFiles/malloc_library.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_library.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anshu/Project/malloc-library/main.c > CMakeFiles/malloc_library.dir/main.c.i

CMakeFiles/malloc_library.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_library.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anshu/Project/malloc-library/main.c -o CMakeFiles/malloc_library.dir/main.c.s

CMakeFiles/malloc_library.dir/TreeNode.c.o: CMakeFiles/malloc_library.dir/flags.make
CMakeFiles/malloc_library.dir/TreeNode.c.o: ../TreeNode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anshu/Project/malloc-library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/malloc_library.dir/TreeNode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_library.dir/TreeNode.c.o   -c /Users/anshu/Project/malloc-library/TreeNode.c

CMakeFiles/malloc_library.dir/TreeNode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_library.dir/TreeNode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anshu/Project/malloc-library/TreeNode.c > CMakeFiles/malloc_library.dir/TreeNode.c.i

CMakeFiles/malloc_library.dir/TreeNode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_library.dir/TreeNode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anshu/Project/malloc-library/TreeNode.c -o CMakeFiles/malloc_library.dir/TreeNode.c.s

# Object files for target malloc_library
malloc_library_OBJECTS = \
"CMakeFiles/malloc_library.dir/main.c.o" \
"CMakeFiles/malloc_library.dir/TreeNode.c.o"

# External object files for target malloc_library
malloc_library_EXTERNAL_OBJECTS =

malloc_library: CMakeFiles/malloc_library.dir/main.c.o
malloc_library: CMakeFiles/malloc_library.dir/TreeNode.c.o
malloc_library: CMakeFiles/malloc_library.dir/build.make
malloc_library: CMakeFiles/malloc_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anshu/Project/malloc-library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable malloc_library"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/malloc_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloc_library.dir/build: malloc_library

.PHONY : CMakeFiles/malloc_library.dir/build

CMakeFiles/malloc_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/malloc_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/malloc_library.dir/clean

CMakeFiles/malloc_library.dir/depend:
	cd /Users/anshu/Project/malloc-library/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anshu/Project/malloc-library /Users/anshu/Project/malloc-library /Users/anshu/Project/malloc-library/cmake-build-debug /Users/anshu/Project/malloc-library/cmake-build-debug /Users/anshu/Project/malloc-library/cmake-build-debug/CMakeFiles/malloc_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/malloc_library.dir/depend

