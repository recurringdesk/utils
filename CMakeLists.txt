cmake_minimum_required(VERSION 3.30.0)
project(recurringengine VERSION 6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(UTILS_SOURCE
source/console/logger.cpp
source/utils/string.cpp
source/math/functions.cpp
source/math/objects.cpp)

add_library(recurringutils SHARED ${UTILS_SOURCE})
target_link_libraries(recurringutils PUBLIC glfw3dll)

add_executable(recurringengine source/main.cpp source/window.cpp)
target_link_libraries(recurringengine PUBLIC recurringutils glfw3dll)
