cmake_minimum_required(VERSION 3.0)

# set the project name
project(OOP_ClassesAndObjects)

# point the compiler to build with C++14
set(CMAKE_CXX_STANDARD 14)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

# add compilation flag to print warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# generate binary inside bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# generate library inside lib folder
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

# Include path for headers
set(INC ${CMAKE_HOME_DIRECTORY}/include)
include_directories(${INC})

# library source
set(LIB_SRC lib_src/Player.cpp
            lib_src/Other_class.cpp
            lib_src/Friend_class.cpp)

# show log message during 'cmake CMakeLists.txt' execution
message(${CMAKE_BINARY_DIR})

# Create variable SOURCES to encompass src+lib files  
# set(SOURCES src/main.cpp)

# create libraries (shared or static)
add_library(classesLib SHARED ${LIB_SRC})
#add_library(math STATIC ${LIB_SRC})

# add the executable
add_executable(OOP_ClassesAndObjects src/main.cpp)

# link the binary with the library
target_link_libraries(OOP_ClassesAndObjects classesLib)
