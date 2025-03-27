cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME cellular_automata)
project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 11)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        "master"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME}
        src/main.c
        src/grid.c
        src/cell.c
        src/input.c
        src/game.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
