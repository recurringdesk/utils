cmake_minimum_required(VERSION 3.30.0)
project(recurringutils VERSION 6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(RECURRING_CORE_SOURCE
    source/console/logger.cpp
    source/utils/string.cpp
    source/math/functions.cpp
    source/math/objects.cpp
    source/core/window.cpp)

add_executable(recurring source/core/main.cpp ${RECURRING_CORE_SOURCE})
target_link_libraries(recurring PRIVATE glfw3dll glad)

enable_testing()

add_subdirectory(tests)
