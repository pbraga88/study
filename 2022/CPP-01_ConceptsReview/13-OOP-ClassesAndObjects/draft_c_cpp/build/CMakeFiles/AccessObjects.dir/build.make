# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/AccessObjects.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AccessObjects.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AccessObjects.dir/flags.make

CMakeFiles/AccessObjects.dir/src/main.c.o: CMakeFiles/AccessObjects.dir/flags.make
CMakeFiles/AccessObjects.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AccessObjects.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AccessObjects.dir/src/main.c.o   -c /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/src/main.c

CMakeFiles/AccessObjects.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AccessObjects.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/src/main.c > CMakeFiles/AccessObjects.dir/src/main.c.i

CMakeFiles/AccessObjects.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AccessObjects.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/src/main.c -o CMakeFiles/AccessObjects.dir/src/main.c.s

# Object files for target AccessObjects
AccessObjects_OBJECTS = \
"CMakeFiles/AccessObjects.dir/src/main.c.o"

# External object files for target AccessObjects
AccessObjects_EXTERNAL_OBJECTS =

bin/AccessObjects: CMakeFiles/AccessObjects.dir/src/main.c.o
bin/AccessObjects: CMakeFiles/AccessObjects.dir/build.make
bin/AccessObjects: lib/liblinkedListLib.so
bin/AccessObjects: CMakeFiles/AccessObjects.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/AccessObjects"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AccessObjects.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AccessObjects.dir/build: bin/AccessObjects

.PHONY : CMakeFiles/AccessObjects.dir/build

CMakeFiles/AccessObjects.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AccessObjects.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AccessObjects.dir/clean

CMakeFiles/AccessObjects.dir/depend:
	cd /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/build /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/build /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/13-OOP-ClassesAndObjects/draft_c_cpp/build/CMakeFiles/AccessObjects.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AccessObjects.dir/depend

