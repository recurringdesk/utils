cmake_minimum_required(VERSION 3.30.0)
project(recurringutils VERSION 6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CONSOLE_SOURCE
    source/console/logger.cpp)

set(UTILS_SOURCE
    source/utils/string.cpp)

set(MATH_SOURCE
    source/math/functions.cpp
    source/math/objects.cpp)

add_library(recurringutils SHARED ${CONSOLE_SOURCE} ${MATH_SOURCE} ${UTILS})
include_directories(include)

enable_testing()

add_subdirectory(tests)
