cmake_minimum_required(VERSION 3.16)

# Rename main\
set(EXTRA_COMPONENT_DIRS ${CMAKE_CURRENT_LIST_DIR}/core)


# Rename build\ ? 
# Maybe, Espressif still uses build though

set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/../bin)


include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(hello_world)
