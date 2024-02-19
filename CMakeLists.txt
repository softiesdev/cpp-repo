cmake_minimum_required(VERSION 3.19)
project(cpp_repo LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(cpp_repo src/main.cpp src/module1.cpp src/module2.cpp)
target_include_directories(cpp_repo PUBLIC inc)
set_property(TARGET cpp_repo PROPERTY CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
  cpp_repo_test
  test/module1Test.cpp
  test/module1Test.hpp
)
target_link_libraries(
  cpp_repo_test
  GTest::gtest_main
)

include(GoogleTest)
file(MAKE_DIRECTORY report)
gtest_discover_tests(cpp_repo_test XML_OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/test-reports)
