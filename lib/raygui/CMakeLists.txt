cmake_minimum_required(VERSION 3.11)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(raygui C)

# Config options
option(BUILD_RAYGUI_EXAMPLES "Build the examples." ON)

# Directory Variables
set(RAYGUI_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(RAYGUI_SRC ${RAYGUI_ROOT}/src)

# raygui
add_library(raygui INTERFACE)
file(GLOB sources ${RAYGUI_SRC}/*.h)
set(RAYGUI_HEADERS ${sources})
install(FILES
        ${RAYGUI_HEADERS} DESTINATION include
        )
target_include_directories(raygui INTERFACE ${RAYGUI_SRC})