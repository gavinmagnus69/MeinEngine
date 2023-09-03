cmake_minimum_required(VERSION 3.25)
project(MeinEngine)

set(CMAKE_CXX_STANDARD 23)
include_directories("C:/romanfiles/MeinEngine/App")
include_directories("C:/romanfiles/MeinEngine/Engine")
add_executable(MeinEngine main.cpp Engine/Window.h Engine/Window.cpp
        App/AppWindow.h
        App/AppWindow.cpp)
