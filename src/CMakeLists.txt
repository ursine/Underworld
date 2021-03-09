find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(tinyobjloader REQUIRED FATAL_ERROR)

add_executable(vulkantest main.cpp tdgvulkan.h tdgvkdebug.h stb_image.h)
target_link_libraries (vulkantest glfw Vulkan::Vulkan)
target_include_directories (vulkantest PUBLIC
        ${Vulkan_INCLUDE_DIRS} ${glfw3_INCLUDE_DIRS} ${tinyobjloader_INCLUDE_DIRS}
        )
