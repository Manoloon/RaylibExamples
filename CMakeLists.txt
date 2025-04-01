cmake_minimum_required(VERSION 3.25.0)
project(RaylibExamples VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD C11)
set(CMAKE_C_STANDARD_REQUIRED ON)
find_package(RAYLIB REQUIRED)

add_compile_options(-std=c11 -Wall -Wextra -Wpedantic -Wshadow)

add_executable(RaylibExamples main.c)
target_link_libraries(RaylibExamples raylib)

