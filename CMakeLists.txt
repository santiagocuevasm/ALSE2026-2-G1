cmake_minimum_required(VERSION 3.10)
project(Corte2_Entregable2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(incluir)

add_executable(ejecutable_corte2
    src/main.cpp
    src/Sphere.cpp
    src/robot_simulator.cpp
    src/queen_attack.cpp
    src/twitter.cpp
    src/spreadsheet.cpp
)
