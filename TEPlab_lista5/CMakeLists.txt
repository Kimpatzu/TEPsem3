cmake_minimum_required(VERSION 3.20)
project(TEPlab_lista5)

set(CMAKE_CXX_STANDARD 98)

add_executable(TEPlab_lista5 main.cpp CMySmartPointer.h CRefCounter.cpp CRefCounter.h CTab.cpp CTab.h Aclass.cpp)
