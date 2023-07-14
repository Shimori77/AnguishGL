cmake_minimum_required(VERSION 3.26)
project(
        anguish_gl_lib
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")

set(
        SOURCES
        src/gl.c
        src/core/window.cpp src/gfx/mesh/mesh.cpp src/gfx/mesh/mesh_loader.cpp src/gfx/shader/shader.cpp
        src/gfx/shader/shader_program.cpp
        src/gfx/texture/texture.cpp src/gfx/texture/texture_loader.cpp src/gfx/object.cpp src/core/math.cpp)

find_package(OpenGL REQUIRED)
find_package(OpenAL REQUIRED)
find_package(GLM 0.9.9.8 EXACT REQUIRED)
find_package(GLFW 3.3.8 EXACT REQUIRED)
find_package(LZ4 1.9.4 EXACT REQUIRED)
find_package(XXHASH 0.8.1 EXACT REQUIRED)
find_package(OPUS REQUIRED)

add_library(anguish_gl_lib SHARED ${SOURCES})
target_include_directories(anguish_gl_lib PUBLIC include
        ${GLM_INCLUDE_DIRS} ${GLFW_INCLUDE_DIR} ${LZ4_INCLUDE_DIR} ${XXHASH_INCLUDE_DIRS}
        ${OPUS_INCLUDE_DIRS}
)
target_link_libraries(anguish_gl_lib PUBLIC
        OpenGL::GL ${GLFW_LIBRARY} ${LZ4_LIBRARY} ${XXHASH_LIBRARIES}
        ${OPUS_LIBRARIES}
)

set_target_properties(anguish_gl_lib PROPERTIES OUTPUT_NAME "anguish")
