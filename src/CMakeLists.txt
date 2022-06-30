cmake_minimum_required(VERSION 3.0.0)
project(sfml_game VERSION 0.1.0)

include_directories(Assets)

add_executable(sfml_game ${game_src} main.cpp)

target_link_libraries(sfml_game PUBLIC sfml-graphics sfml-audio sfml-window sfml-system)


