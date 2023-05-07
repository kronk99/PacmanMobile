cmake_minimum_required(VERSION 3.25)
project(PacmanMobile)

set(CMAKE_CXX_STANDARD 17)
add_executable(PacmanMobile main.cpp Game.cpp Game.h textureLoader.cpp Map.h Map.cpp Player.cpp Enemy.cpp Score.cpp enemyHndlr.cpp Vida.cpp pathfindingA.cpp Node.h Lista.cpp Node.cpp)
target_link_libraries(PacmanMobile SDL2main SDL2 SDL2_image SDL2_ttf)
