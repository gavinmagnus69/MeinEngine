cmake_minimum_required(VERSION 3.25)
project(MeinEngine)

set(CMAKE_CXX_STANDARD 23)
include_directories("C:/romanfiles/MeinEngine/App")
include_directories("C:/romanfiles/MeinEngine/Engine")
include_directories("C:/romanfiles/MeinEngine/Engine/GraphicsEngine")
include_directories("C:/romanfiles/MeinEngine/Engine/GraphicsEngine/SwapChain")


add_executable(MeinEngine main.cpp Engine/Windowing/Window.h Engine/Windowing/Window.cpp
        App/AppWindow.h
        App/AppWindow.cpp
        Engine/GraphicsEngine/GraphicsEngine.h
        Engine/GraphicsEngine/GraphicsEngine.cpp
        Engine/GraphicsEngine/SwapChain/SwapChain.h
        Engine/GraphicsEngine/SwapChain/SwapChain.cpp)

target_link_libraries(MeinEngine PUBLIC d3d11.lib)