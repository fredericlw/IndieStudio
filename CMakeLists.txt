cmake_minimum_required(VERSION 3.17)
project(bomberman)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
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
        Include/Components/TransformComp.cpp
        Include/Components/TransformComp.hpp
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
        Include/Components/Components.h
        Include/Components/ButtonComp.cpp
        Include/Components/ButtonComp.hpp
        Include/raylib/Vector3D.cpp
        Include/raylib/Vector3D.hpp
        Include/raylib/Vector2D.cpp
        Include/raylib/Vector2D.hpp
        Include/Components/BasicCubeComp.cpp Include/Components/BasicCubeComp.hpp Source/Scenes/GameScene.cpp)


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/lib/raylib/)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(raylib REQUIRED QUIET)

target_link_libraries(bomberman raylib)
