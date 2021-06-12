cmake_minimum_required(VERSION 3.17)
project(bomberman)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    message(msvc)
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)

include_directories(Include Include/Components Include/ECS)

add_executable(bomberman
        Include/Bomberman.hpp
        Include/Colors.h

        Include/Components/Components.h

        Include/Components/3D/BasicCubeComp.hpp
        Include/Components/3D/MeshCubeComp.hpp
        Include/Components/3D/MeshCubeComp.hpp
        Include/Components/3D/ModelComp.hpp
        Include/Components/3D/TransformComp.hpp

        Include/Components/Character/MovementComp.hpp
        Include/Components/Character/PlayerComp.hpp

        Include/Components/GUI/AnimatedSprite.hpp
        Include/Components/GUI/ButtonComp.hpp
        Include/Components/GUI/ListSelectorComp.hpp
        Include/Components/GUI/LobbyComp.hpp
        Include/Components/GUI/OptionComp.hpp
        Include/Components/GUI/PlayerHUD.hpp
        Include/Components/GUI/Sprite2D.hpp
        Include/Components/GUI/TextComp.hpp

        Include/Components/Logic/BombComp.hpp
        Include/Components/Logic/GameLogicComp.hpp
        Include/Components/Logic/MapComponent.hpp
        Include/Components/Logic/MapComponent.hpp
        Include/Components/Logic/SoundEffectComp.hpp

        Include/ECS/Component.hpp
        Include/ECS/Ecs.hpp
        Include/ECS/Entity.hpp
        Include/ECS/Manager.hpp

        Include/Keys.h

        Include/raylib_encap/ECamera.hpp
        Include/raylib_encap/ECube.hpp
        Include/raylib_encap/ECube.hpp
        Include/raylib_encap/EMeshCube.hpp
        Include/raylib_encap/EMeshCube.hpp
        Include/raylib_encap/EModel.hpp
        Include/raylib_encap/ERect.hpp
        Include/raylib_encap/ESprite.hpp
        Include/raylib_encap/EText.hpp
        Include/raylib_encap/EAudio.hpp
        Include/raylib_encap/EMusic.hpp
        Include/raylib_encap/ESound.hpp
        Include/raylib_encap/Input/AInputModule.hpp
        Include/raylib_encap/Input/EGamepadInputModule.hpp
        Include/raylib_encap/Input/EKeyboardInputModule.hpp
        Include/raylib_encap/Input/EMouseInputModule.hpp
        Include/raylib_encap/Math/CubeCollider.cpp
        Include/raylib_encap/Math/CubeCollider.hpp
        Include/raylib_encap/Math/Random.hpp
        Include/raylib_encap/Math/Random.hpp
        Include/raylib_encap/Math/RectCollider.hpp
        Include/raylib_encap/Math/Vector2D.hpp
        Include/raylib_encap/Math/Vector3D.hpp
        Include/raylib_encap/Window.hpp

        Include/Scene.hpp
        Source/Bomberman.cpp

        Source/Components/3D/AnimatedSprite.cpp
        Source/Components/3D/BasicCubeComp.cpp
        Source/Components/3D/MeshCubeComp.cpp
        Source/Components/3D/MeshCubeComp.cpp
        Source/Components/3D/ModelComp.cpp
        Source/Components/3D/TransformComp.cpp
        Source/Components/Character/MovementComp.cpp
        Source/Components/Character/PlayerComp.cpp
        Source/Components/GUI/ButtonComp.cpp
        Source/Components/GUI/ListSelectorComp.cpp
        Source/Components/GUI/OptionComp.cpp
        Source/Components/GUI/PlayerHUD.cpp
        Source/Components/GUI/Sprite2D.cpp
        Source/Components/GUI/TextComp.cpp
        Source/Components/Logic/BombComp.cpp
        Source/Components/Logic/GameLogicComp.cpp
        Source/Components/Logic/LobbyComp.cpp
        Source/Components/Logic/MapComponent.cpp
        Source/Components/Logic/MapComponent.cpp
        Source/Components/Logic/SoundEffectComp.cpp

        Source/ECS/Component.cpp
        Source/ECS/Entity.cpp
        Source/ECS/Manager.cpp

        Source/main.cpp

        Source/raylib_encap/ECamera.cpp
        Source/raylib_encap/ECube.cpp
        Source/raylib_encap/ECube.cpp
        Source/raylib_encap/EMeshCube.cpp
        Source/raylib_encap/EMeshCube.cpp
        Source/raylib_encap/EModel.cpp
        Source/raylib_encap/ERect.cpp
        Source/raylib_encap/ESprite.cpp
        Source/raylib_encap/EText.cpp
        Source/raylib_encap/EAudio.cpp
        Source/raylib_encap/EMusic.cpp
        Source/raylib_encap/ESound.cpp
        Source/raylib_encap/EAnimatedModel.cpp
        Source/raylib_encap/Input/AInputModule.cpp
        Source/raylib_encap/Input/EGamepadInputModule.cpp
        Source/raylib_encap/Input/EKeyboardInputModule.cpp
        Source/raylib_encap/Input/EMouseInputModule.cpp
        Source/raylib_encap/Math/Random.cpp
        Source/raylib_encap/Math/Random.cpp
        Source/raylib_encap/Math/RectCollider.cpp
        Source/raylib_encap/Math/Vector2D.cpp
        Source/raylib_encap/Math/Vector3D.cpp
        Source/raylib_encap/Window.cpp

        Source/Scenes/GameScene.cpp
        Source/Scenes/LobbyScene.cpp
        Source/Scenes/LobbyScene.cpp
        Source/Scenes/MainMenuScene.cpp
        Source/Scenes/OptionScene.cpp
        Source/Scenes/HowToPlay.cpp
        Include/Components/Character/powerup.hpp
        Include/raylib_encap/Easing.hpp
        Source/raylib_encap/Easing.cpp
        Source/Components/AssetLoader.cpp
        Include/Components/AssetLoader.hpp
        Source/raylib_encap/EAnimatedModel.cpp
        Include/raylib_encap/EAnimatedModel.hpp
        Source/Components/3D/AnimatedModel.cpp
        Include/Components/3D/AnimatedModel.hpp
        Source/Components/PowerUpComp.cpp
        Include/Components/Logic/PowerUpComp.hpp
        Include/BaseValues.h
        Source/Components/GUI/MainMenuComponent.cpp
        Include/Components/GUI/MainMenuComponent.hpp
        Source/Components/GUI/BackgroundComponent.cpp
        Include/Components/GUI/BackgroundComponent.hpp
        Source/Components/GUI/PauseMenuComp.cpp
        Include/Components/GUI/PauseMenuComp.hpp
        Source/Scenes/GameOverScene.cpp
        Sources/Components/GUI/ResizableTextComp.cpp
        Include/Components/GUI/ResizableTextComp.hpp
        Source/Scenes/ControlsScene.cpp)

#raylib
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/lib/raylib/)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(raylib REQUIRED QUIET)

#boost
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
#find_package(Boost 1.76.0 COMPONENTS filesystem)
#
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    add_executable(progname file1.cxx file2.cxx)
#    target_link_libraries(progname ${Boost_LIBRARIES})
#endif()

target_link_libraries(bomberman raylib)