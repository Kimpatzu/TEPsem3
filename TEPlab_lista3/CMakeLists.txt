cmake_minimum_required(VERSION 3.20)
project(TEPlab_lista3)

set(CMAKE_CXX_STANDARD 98)

add_executable(TEPlab_lista3 main.cpp CNodeStatic.cpp CNodeStatic.h CTreeStatic.cpp CTreeStatic.h CNodeDynamic.cpp CNodeDynamic.h CTreeDynamic.cpp CTreeDynamic.h)
