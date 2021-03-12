find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(tinyobjloader REQUIRED FATAL_ERROR)
find_package(glm REQUIRED FATAL_ERROR)
find_package(glslang REQUIRED FATAL_ERROR)

IF (!WIN32)
    find_package(glfw3 REQUIRED FATAL_ERROR)
ENDIF()

add_executable(vulkantest main.cpp tdgvulkan.h tdgvkdebug.h stb_image.h tdgglslcompiler.h)
target_link_libraries (vulkantest glfw Vulkan::Vulkan glslang)
target_include_directories (vulkantest PUBLIC
        ${Vulkan_INCLUDE_DIRS} ${glfw3_INCLUDE_DIRS} ${tinyobjloader_INCLUDE_DIRS} ${glm_INCLUDE_DIRS}
        ${glslang_INCLUDE_DIRS}
        )
