cmake_minimum_required(VERSION 3.5)

project(my_project)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    lib_src/Account.cpp
    lib_src/Account_Util.cpp
    lib_src/Checking_Account.cpp
    lib_src/I_Printable.cpp
    lib_src/Savings_Account.cpp
    lib_src/Trust_Account.cpp
    src/main.cpp
)

# Create an executable
add_executable(my_program ${SOURCES})
