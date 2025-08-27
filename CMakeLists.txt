cmake_minimum_required(VERSION 3.31)
project(recurringutils VERSION 9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dependencies/glfw)

if (WIN32)
add_compile_definitions(RLIB_EXPORT)
endif ()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(recore SHARED
            source/console/logger.cpp
            source/utils/string.cpp
            source/math/functions.cpp
            source/math/objects.cpp
            source/core/window.cpp
            source/core/buffer_manager.cpp)

target_include_directories(recore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (WIN32)
target_link_libraries(recore PUBLIC glfw glew32 opengl32)
elseif(LINUX)
target_link_libraries(recore PUBLIC glfw GL GLEW)
endif ()
