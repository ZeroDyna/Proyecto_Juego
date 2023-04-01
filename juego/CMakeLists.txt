cmake_minimum_required(VERSION 3.0)

project(Game)

set(CMAKE_CXX_STANDARD 11)

# Busca la biblioteca SFML y enlázala con tu proyecto
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Agrega el archivo de código fuente a tu proyecto
add_executable(Game Personaje.cpp Personaje.hpp main.cpp)

# Enlaza la biblioteca SFML con tu proyecto
target_link_libraries(Game sfml-graphics)

