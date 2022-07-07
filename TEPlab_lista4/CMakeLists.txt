cmake_minimum_required(VERSION 3.20)
project(TEPlab_lista4)

set(CMAKE_CXX_STANDARD 98)

add_executable(TEPlab_lista4 main.cpp cmake-build-debug/CNodeDynamic.cpp cmake-build-debug/CNodeDynamic.h cmake-build-debug/CTreeDynamic.cpp cmake-build-debug/CTreeDynamic.h)
