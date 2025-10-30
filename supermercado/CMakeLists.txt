cmake_minimum_required(VERSION 3.10)
project(Supermercado)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Supermercado
    src/main.cpp
    src/producto.cpp
    src/itemcarrito.cpp
    src/usuario.cpp
)
