cmake_minimum_required(VERSION 3.5)
project(list)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests LinkedList.cpp googletest/gtests.cpp)
target_link_libraries(tests gtest_main gmock)
add_test(NAME tests COMMAND tests) 

add_executable(list main.cpp LinkedList.cpp)