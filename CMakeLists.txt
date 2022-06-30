cmake_minimum_required(VERSION 3.21)
project(sfml_game)
include(CTest)
include(cmake/doctest.cmake)

set(CMAKE_CXX_STANDARD 20)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "./SFML/lib/cmake/SFML/")
set(SFML_ROOT ${SFML_DIR})

set(CMAKE_MODULE_PATH "${SFML_DIR}/lib/cmake/SFML" ${CMAKE_MODULE_PATH})


file(GLOB game_src "src/**/*.cpp" "src/Game/Utils/debug.cpp" "main.cpp" "settings.toml" "src/external/SimplexNoise/*.cpp")
list(FILTER game_src EXCLUDE REGEX "src/Tests/Tests.cpp")
find_package(SFML 2.5.1 COMPONENTS  window system graphics audio REQUIRED)

file(COPY ${CMAKE_SOURCE_DIR}/SFML/bin/openal32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/src)
file(COPY ${CMAKE_SOURCE_DIR}/SFML/bin/openal32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/src/Tests)

add_subdirectory (src/)

enable_testing()
add_subdirectory (src/Tests)
