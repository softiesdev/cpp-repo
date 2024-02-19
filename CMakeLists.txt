cmake_minimum_required(VERSION 3.19)
project(cpp_repo LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(cpp_repo src/main.cpp src/module1.cpp src/module2.cpp)
target_include_directories(cpp_repo PUBLIC inc)

