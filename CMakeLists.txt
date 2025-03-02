cmake_minimum_required(VERSION 3.20)
project(unlambda-cpp)
set(SOURCES src/main.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This is bad practice but it's my project so I can do what I want
set(CMAKE_C_COMPILER "/usr/bin/clang-19")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-19")

add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++ -lc++abi)

add_executable(unlambda-cpp ${SOURCES})

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/df1544bcee0c7ce35cd5ea0b3eb8cc81855a4140.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TEST_SOURCES
  tests/test.cpp
)

add_executable(
    test-implementation
    ${TEST_SOURCES}
)
target_link_libraries(
    test-implementation
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test-implementation)

