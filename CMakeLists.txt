cmake_minimum_required(VERSION 3.16)
project(vulkantest)

set(CMAKE_CXX_STANDARD 17)

IF (WIN32)
add_subdirectory(E:/glfw3 thirdparty/glfw3)
ENDIF()

add_subdirectory(src)