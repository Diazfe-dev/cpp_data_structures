cmake_minimum_required(VERSION 3.10)
project(listas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar todos los archivos fuente
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Crear ejecutable
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

# Configurar directorio de salida
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output
)
