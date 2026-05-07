cmake_minimum_required(VERSION 4.2)
project(viSim___visualisation_Simulation C)

set(CMAKE_C_STANDARD 11)

find_package(raylib REQUIRED)

add_executable(viSim___visualisation_Simulation main.c)


target_link_libraries(viSim___visualisation_Simulation PRIVATE raylib)