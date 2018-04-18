cmake_minimum_required(VERSION 3.8)
project(SClone)

set(CMAKE_CXX_STANDARD 11)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")

add_subdirectory(Dependencies/glfw)
include_directories(Dependencies/glfw/include)

include_directories(Dependencies/glew/include)
link_directories(Dependencies/glew/lib/Release/x64)

add_definitions(-DGLEW_STATIC)

include_directories(Dependencies/glm)

add_subdirectory(src)



