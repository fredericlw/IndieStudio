cmake_minimum_required(VERSION 3.17)
project(bomberman)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    message(coucou)
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)

include_directories(Include Include/Components Include/ECS)

add_executable(bomberman
        Include/Bomberman.hpp

        Source/main.cpp

        Source/Bomberman.cpp
        Source/raylib_encap/Window.cpp
        Include/raylib_encap/Window.hpp
        Include/ECS/Ecs.hpp
        Source/Components/TransformComp.cpp
        Include/Components/3D/TransformComp.hpp
        Source/ECS/Manager.cpp
        Include/ECS/Manager.hpp
        Source/ECS/Entity.cpp
        Include/ECS/Entity.hpp
        Source/ECS/Component.cpp
        Include/ECS/Component.hpp
        Include/Scene.hpp

        Source/Components/Sprite2D.cpp
        Include/Components/GUI/Sprite2D.hpp

        Source/Scenes/MainMenuScene.cpp
        Include/Components/Components.h
        Source/Components/ButtonComp.cpp
        Include/Components/GUI/ButtonComp.hpp
        Source/raylib_encap/Math/Vector3D.cpp
        Include/raylib_encap/Math/Vector3D.hpp
        Source/raylib_encap/Math/Vector2D.cpp
        Include/raylib_encap/Math/Vector2D.hpp
        Source/Components/BasicCubeComp.cpp
        Include/Components/3D/BasicCubeComp.hpp
        Source/Scenes/GameScene.cpp
        Source/raylib_encap/ESprite.cpp
        Include/raylib_encap/ESprite.hpp
        Source/raylib_encap/ERect.cpp
        Include/raylib_encap/ERect.hpp
        Source/raylib_encap/Math/RectCollider.cpp
        Include/raylib_encap/Math/RectCollider.hpp
        Source/raylib_encap/ECamera.cpp
        Include/raylib_encap/ECamera.hpp
        Source/raylib_encap/Input/EKeyboardInputModule.cpp
        Include/raylib_encap/Input/EKeyboardInputModule.hpp
        Source/raylib_encap/Input/EMouseInputModule.cpp
        Include/raylib_encap/Input/EMouseInputModule.hpp
        Source/raylib_encap/Input/EGamepadInputModule.cpp
        Include/raylib_encap/Input/EGamepadInputModule.hpp
        Include/Keys.h
        Source/Components/MovementComp.cpp
        Include/Components/Character/MovementComp.hpp
        Source/raylib_encap/Input/AInputModule.cpp
        Include/raylib_encap/Input/AInputModule.hpp
        Source/raylib_encap/EText.cpp
        Include/raylib_encap/EText.hpp
        Include/Colors.h
        Source/raylib_encap/ECube.cpp Include/raylib_encap/ECube.hpp Source/Scenes/MapComponent.cpp Source/Scenes/MapComponent.hpp Source/raylib_encap/Math/Random.cpp Include/raylib_encap/Math/Random.hpp Source/Components/MeshCubeComp.cpp Include/Components/3D/MeshCubeComp.hpp Source/raylib_encap/EMeshCube.cpp Include/raylib_encap/EMeshCube.hpp Source/Scenes/LobbyScene.cpp Source/raylib_encap/EModel.cpp Include/raylib_encap/EModel.hpp Include/Components/3D/ModelComp.cpp Include/Components/3D/ModelComp.hpp)


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/lib/raylib/)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(raylib REQUIRED QUIET)

target_link_libraries(bomberman raylib)
