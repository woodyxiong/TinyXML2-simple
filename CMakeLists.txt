cmake_minimum_required(VERSION 3.8)
project(TinyXML2_simple)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        tinyxml2/simple.cpp
        tinyxml2/simple.h
        tinyxml2/tinyxml2.cpp
        tinyxml2/tinyxml2.h
        main.cpp)

add_executable(TinyXML2_simple ${SOURCE_FILES})