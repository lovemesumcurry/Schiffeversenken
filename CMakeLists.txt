cmake_minimum_required(VERSION 3.24)
project(Schiffeversenken)

set(CMAKE_CXX_STANDARD 23)

add_executable(Schiffeversenken "play_battleground.cpp" BattleGround.cpp BattleGround.h)
