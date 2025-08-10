cmake_minimum_required(VERSION 3.30.0)
project(recurringutils VERSION 4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MATH source/math)
set(CONSOLE source/console)
set(UTILS source/utils)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CONSOLE_SOURCE
    ${CONSOLE}/logger.cpp)

set(UTILS_SOURCE
    ${UTILS}/string.cpp)

set(MATH_SOURCE
    ${MATH}/functions.cpp
    ${MATH}/objects.cpp)

add_library(recurringutils SHARED ${CONSOLE_SOURCE} ${MATH_SOURCE})
include_directories(include)