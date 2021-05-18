cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)

include_directories(Include)

add_executable(bomberman
        Include/Bomberman.hpp

        Source/main.cpp

        Source/Bomberman.cpp
        Include/raylib/Window.cpp
        Include/raylib/Window.hpp
        Include/ECS/Ecs.hpp
        Include/Components/PositionComponent.cpp
        Include/Components/PositionComponent.hpp
        Include/ECS/Manager.cpp
        Include/ECS/Manager.hpp
        Include/ECS/Entity.cpp
        Include/ECS/Entity.hpp
        Include/ECS/Component.cpp
        Include/ECS/Component.hpp
        Include/Scene.hpp

        Include/Components/Sprite2D.cpp
        Include/Components/Sprite2D.hpp

        Source/Scenes/MainMenuScene.cpp
        Source/Scenes/MainMenuScene.hpp
        Include/Components/Components.h)


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/lib/raylib/)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(raylib REQUIRED QUIET)

target_link_libraries(bomberman raylib)
