cmake_minimum_required(VERSION 3.25.0)
project(RaylibExamples VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-std=c11 -Wall -Wextra -Wpedantic -Wshadow)

find_package(raylib REQUIRED)

# Define the main source directory for clarity
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(RaylibExamples main.c)
target_include_directories(RaylibExamples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(RaylibExamples raylib)

