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
CMAKE_SOURCE_DIR = /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/build

# Include any dependencies generated for this target.
include CMakeFiles/OperatorOveloading.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OperatorOveloading.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OperatorOveloading.dir/flags.make

CMakeFiles/OperatorOveloading.dir/src/main.cpp.o: CMakeFiles/OperatorOveloading.dir/flags.make
CMakeFiles/OperatorOveloading.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OperatorOveloading.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OperatorOveloading.dir/src/main.cpp.o -c /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/src/main.cpp

CMakeFiles/OperatorOveloading.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OperatorOveloading.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/src/main.cpp > CMakeFiles/OperatorOveloading.dir/src/main.cpp.i

CMakeFiles/OperatorOveloading.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OperatorOveloading.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/src/main.cpp -o CMakeFiles/OperatorOveloading.dir/src/main.cpp.s

# Object files for target OperatorOveloading
OperatorOveloading_OBJECTS = \
"CMakeFiles/OperatorOveloading.dir/src/main.cpp.o"

# External object files for target OperatorOveloading
OperatorOveloading_EXTERNAL_OBJECTS =

bin/OperatorOveloading: CMakeFiles/OperatorOveloading.dir/src/main.cpp.o
bin/OperatorOveloading: CMakeFiles/OperatorOveloading.dir/build.make
bin/OperatorOveloading: lib/libopOverloadLib.so
bin/OperatorOveloading: CMakeFiles/OperatorOveloading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/OperatorOveloading"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OperatorOveloading.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OperatorOveloading.dir/build: bin/OperatorOveloading

.PHONY : CMakeFiles/OperatorOveloading.dir/build

CMakeFiles/OperatorOveloading.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OperatorOveloading.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OperatorOveloading.dir/clean

CMakeFiles/OperatorOveloading.dir/depend:
	cd /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/build /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/build /home/pbraga/Workspace/Pessoal/Repositories/Study/study/2022/CPP-01_ConceptsReview/14-OperatorOverloading/09_CODING_EXERCISE_OperatorOverloadingTheStreamInsertionOperator/build/CMakeFiles/OperatorOveloading.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OperatorOveloading.dir/depend

