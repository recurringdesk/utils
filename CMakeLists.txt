cmake_minimum_required(VERSION 3.30.0)
project(recurringutils VERSION 9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dependencies/glfw)

add_compile_definitions(RLIB_EXPORT)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(RECURRING_CORE_SOURCE
    source/console/logger.cpp
    source/utils/string.cpp
    source/math/functions.cpp
    source/math/objects.cpp)

set(RECURRING_UI_SOURCE
    source/core/window.cpp
    source/core/buffer_manager.cpp)

add_library(recore SHARED ${RECURRING_CORE_SOURCE})
add_library(regui SHARED ${RECURRING_UI_SOURCE})
target_include_directories(recore PUBLIC include)
target_include_directories(regui PUBLIC include)
target_link_libraries(regui PUBLIC glfw glew32 opengl32 recore)

enable_testing()

add_subdirectory(tests)
