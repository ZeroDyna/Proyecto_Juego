cmake_minimum_required(VERSION 3.1)

project(juego)

# Añade la carpeta "img" al path para buscar las imágenes
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Busca la biblioteca de SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Añade los archivos fuente al proyecto
add_executable(juego main.cpp Personaje.cpp Personaje.hpp fondo.cpp fondo.hpp disparo.hpp disparo.cpp objeto.hpp objeto.cpp asteroide.hpp asteroide.cpp )

# Enlaza la biblioteca de SFML al proyecto
target_link_libraries(juego sfml-graphics sfml-audio)

# Copia el archivo de sonido al directorio de salida
configure_file(${CMAKE_SOURCE_DIR}/revival.ogg ${CMAKE_BINARY_DIR}/revival.ogg COPYONLY)

# Añade la carpeta "img" al path para buscar las imágenes
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Copia la carpeta "img" al directorio de salida
file(COPY ${CMAKE_SOURCE_DIR}/img DESTINATION ${CMAKE_BINARY_DIR})
 
