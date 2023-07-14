cmake_minimum_required(VERSION 3.26)
project(anguish_gl_sandbox)

set(CMAKE_CXX_STANDARD 23)

set(
        SOURCES
        src/main.cpp
        include/basic_shader.hpp src/basic_shader.cpp src/basic_renderer.cpp src/game_object.cpp)

add_executable(anguish_sandbox ${SOURCES})
target_include_directories(anguish_sandbox PRIVATE ./include)
target_link_libraries(anguish_sandbox PRIVATE anguish_gl_lib)