# CMakeList.txt : CMake project for CMakeProject_1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (GoF_Chain_of_Resposibility_ATM "main.cpp" "Chain.h")
