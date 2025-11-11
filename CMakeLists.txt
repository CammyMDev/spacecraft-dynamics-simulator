cmake_minimum_required(VERSION 3.10)
project(Spacecraft_Dynamic_Simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add your executable
add_executable(Spacecraft_Dynamic_Simulator 
src/main.cpp
src/physics.cpp
src/spaceship.cpp
)
