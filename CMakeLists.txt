cmake_minimum_required(VERSION 3.10)
project(Spacecraft_Dynamic_Simulator VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(Spacecraft_Dynamic_Simulator
    src/main.cpp
    src/physics.cpp
    src/spaceship.cpp
)

target_link_libraries(Spacecraft_Dynamic_Simulator PRIVATE SFML::Graphics SFML::Window SFML::System)