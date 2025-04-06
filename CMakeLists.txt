cmake_minimum_required(VERSION 3.10)

project(first_cpp VERSION 1.0)

# include(CTest)
# enable_testing()

add_executable(first_cpp first_cpp.cpp)
set_property(TARGET first_cpp PROPERTY CXX_STANDARD 17)