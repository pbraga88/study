cmake_minimum_required(VERSION 3.0)

project(challenge)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Set the include directory
include_directories(include)

# Add the source files to the project
set(SRC_FILES
    lib_src/Account.cpp
    lib_src/Account_Util.cpp
    lib_src/Savings_Account.cpp
    src/main.cpp
)

# Create the executable target
add_executable(my_executable ${SRC_FILES})