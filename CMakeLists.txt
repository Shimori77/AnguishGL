cmake_minimum_required(VERSION 3.26)
project(anguish_gl)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)
add_subdirectory(sandbox)

add_dependencies(anguish_sandbox anguish_gl_lib)