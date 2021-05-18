cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)

add_executable(bomberman
        Include/Bomberman.hpp

        Source/main.cpp

        Source/Bomberman.cpp
        )


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/lib/raylib/)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(raylib REQUIRED QUIET)
