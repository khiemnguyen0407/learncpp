cmake_minimum_required(VERSION 3.10)

project(helloworld VERSION 1.0)

# include(CTest)
# enable_testing()

add_executable(helloworld helloworld.cpp)
set_property(TARGET helloworld PROPERTY CXX_STANDARD 17)