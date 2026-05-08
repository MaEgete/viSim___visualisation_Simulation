cmake_minimum_required(VERSION 4.2)
project(viSim___visualisation_Simulation C)

set(CMAKE_C_STANDARD 11)

find_package(raylib REQUIRED)

add_executable(viSim___visualisation_Simulation src/main.c
        src/Visualizer.h
        src/Beam.h
        src/Visualizer.c
        src/Beam.c
        tests/beam_tests.c
        tests/runTests.h
        tests/runTests.c
        tests/beam_tests.h)


target_link_libraries(viSim___visualisation_Simulation PRIVATE raylib)