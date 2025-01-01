cmake_minimum_required(VERSION 3.20)
project(unlambda-cpp)
set(SOURCES src/main.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This is bad practice but it's my project so I can do what I want
set(CMAKE_C_COMPILER "clang-19")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-19")

add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++ -lc++abi)

add_executable(unlambda-cpp ${SOURCES})
