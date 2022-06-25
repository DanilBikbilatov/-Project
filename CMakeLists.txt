cmake_minimum_required(VERSION 3.21)
project(sfml_game)
include(CTest)
include(cmake/doctest.cmake)
include(FindPkgConfig)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

file(GLOB game_src "src/**/*.cpp" "src/Game/Utils/debug.cpp" "main.cpp" "settings.toml" "src/external/SimplexNoise/*.cpp")
list(FILTER game_src EXCLUDE REGEX "src/Tests/Tests.cpp")
pkg_check_modules(SFML REQUIRED sfml-window sfml-system sfml-graphics sfml-audio)

add_subdirectory (src/)

enable_testing()
add_subdirectory (src/Tests)
