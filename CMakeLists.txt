cmake_minimum_required(VERSION 3.19)
project(supa_node_native VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

include(NodeJS.cmake)
nodejs_init()

add_nodejs_module(${PROJECT_NAME} main.cpp)