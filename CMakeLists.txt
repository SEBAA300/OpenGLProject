cmake_minimum_required (VERSION 2.6)
project (Game)

find_package(OpenGL)
find_package(GLUT)

# Version number
set (Game_Version_Majnor 0)
set (Game_Version_Minorr 0)

add_executable(Game main.cpp)
