cmake_minimum_required(VERSION 3.13)  # CMake version check
project(AppProject)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

include_directories(Ship)
include_directories(Cargo)

add_library(Cargo Cargo/Cargo.cpp Cargo/Cargo.h)
add_library(Ship Ship/Ship.cpp Ship/Ship.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(app main.cpp)

target_link_libraries(app Cargo)
target_link_libraries(app Ship)